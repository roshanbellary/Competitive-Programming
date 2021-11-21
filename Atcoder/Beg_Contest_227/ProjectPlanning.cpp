/*
Problem:Project Planning
Problem Link: https://atcoder.jp/contests/abc227/tasks/abc227_d
Notes: Took a while to realize that I could binary search based upon a constraint. 
For a particular number of projects P, you take the sum of min(a_i,P). Now if that sum >= K*P then it works as you can always
choose the K greatest in terms of number companies and remove 1 project from them reducing the sum by K and continue doing that
choosing the K greatest each time.
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
int N, K;
ll v[(int)2e5];
int main(){
	setIO();rn(N);rn(K);
    for (int i=0;i<N;i++) rn(v[i]);
    ll s = 0, f=1e18/K;
    while (s!=f){
        ll mid = (s+f+1)/2,sum = 0;
        for (int i=0;i<N;i++) sum+=min(v[i],mid);
        if (sum>=K*mid) s=mid;
        else f=mid-1;
    }
    cout << s << "\n";
}
