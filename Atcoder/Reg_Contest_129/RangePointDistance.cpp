/*
Problem: Range Point Distance
Problem Link: https://atcoder.jp/contests/arc129/tasks/arc129_b
Notes: Think of reducing the distance function to a simpler form
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
#define pb push_back
#define eb emplace_back
#define countbits __builtin_popcount
#define beg0 __builtin_clz
#define terminal0 __builtin_ctz
#define f first
#define s second
int mod=1e9+7;
template <class T> 
void rn(T &n){
    n=0;int m = 1;int c;
    c = getchar();if (c=='-') m=-1;
    for (;c>47 && c<58;c=getchar()){
        n=n*(1<<1)+n*(1<<3)+c-48;
    }
    n*=m;
}
void rw(string &w){
    w="";char c=getchar();
    while (c!=' '&&c!='\n'&&c!=EOF){
        w+=c;c=getchar();
    }
}
void rc(char &c){
	c=getchar();
}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N;
pair<int,int> r[(int)2e5];
pair<int,int> maxc[(int)2e5];
int main(){
	setIO();rn(N);
    for (int i=0;i<N;i++) rn(r[i].f),rn(r[i].s);
    priority_queue<pair<int,int>> lt;
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> gr;
    for (int i=0;i<N;i++){
        if (!i) maxc[i] = r[i];
        else maxc[i]={max(r[i].f,maxc[i-1].f),min(maxc[i-1].s,r[i].s)};
    }
    for (int i=0;i<N;i++){
        if (maxc[i].f<maxc[i].s){
            cout << "0\n";
        }else{
            cout << (abs(maxc[i].s-maxc[i].f)+1)/2 << "\n";
        }
    }

}
