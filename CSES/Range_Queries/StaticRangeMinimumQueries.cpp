/*
Problem: Static Range Minimum Queries
Problem Link: https://cses.fi/problemset/task/1647/
Notes: Basically binary lifting like lca, another possible implementation is to use 
a segment tree
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
inline void rv(int &n){
    n=0;int m=1;char c=getchar();if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar();if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){double p = 0.1;c=getchar();for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}}
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){double p = 0.1;c=getchar();for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}}
    n*=m;
}
inline void rv(string &w){w="";char c=getchar();while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar();}}
inline void rv(char &c){c=getchar();}
template<typename T, typename ...Types>
void rv(T &n, Types&&... args){rv(n);rv(args...);}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
const int MN = 2e5;
const int MJ = 19;
int N, Q, minR[MN][MJ], v[MN];
int main(){
	setIO();rv(N, Q);
    for (int i=0;i<N;i++) rv(v[i]);
    for (int i=0;i<N-1;i++) minR[i][0]=min(v[i],v[i+1]);
    minR[N-1][0]=1e9;
    for (int d=1;d<=log2(N);d++){
        for (int i=0;i<N;i++){
            if (i+(1<<d)>=N) minR[i][d]=1e9;
            else minR[i][d]=min(minR[i+(1<<(d-1))][d-1],minR[i][d-1]);
        }
    }
    for (int i=0;i<Q;i++){
        int a, b, d; rv(a,b);
        a--;b--;d=b-a;
        int mv = v[a];
        for (int j=log2(N);j>=0;j--){
            if ((d&(1<<j))!=0){
                mv=min(minR[a][j],mv);
                a+=(1<<j);
            }
        }
        mv=min(mv,v[b]);
        cout << mv << "\n";
    }
}
