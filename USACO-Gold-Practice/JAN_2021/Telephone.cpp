/*
Problem: Telephone
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=1090
Notes: 
Cool bfs problem where you consider a start by location and breed and move either forward, backward or stay and update breed of cow
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
struct Edge{ll n, b, d;};
const int MN = 5e4;
const int MK = 51;
int N, K, b[MN];
ll dp[MN][MK];
bool m[MK][MK];
queue<Edge> q;
int main(){
	setIO();rv(N, K);
    for (int i=0;i<N;i++) rv(b[i]),b[i]--;
    for (int i=0;i<K;i++){
        string s; rv(s);
        for (int j=0;j<K;j++) m[i][j]=(s[j]=='1');
    }
    for (int i=0;i<K;i++) m[K][i]=m[b[N-1]][i];
    for (int i=0;i<K;i++) m[i][K]=m[i][b[N-1]];
    b[N-1]=K;
    for (int i=0;i<N;i++) for (int j=0;j<=K;j++) dp[i][j]=1e18;
    q.push({0,b[0],0});
    while (!q.empty()){
        Edge n = q.front();q.pop();
        if (n.d>dp[n.n][n.b]) continue;
        if (m[n.b][b[n.n]]&&dp[n.n][b[n.n]]==1e18) dp[n.n][b[n.n]]=n.d,q.push({n.n,b[n.n],n.d});
        if (n.n<N-1 && dp[n.n+1][n.b]==1e18) dp[n.n+1][n.b]=n.d+1,q.push({n.n+1,n.b,n.d+1});
        if (n.n>0 && dp[n.n-1][n.b]==1e18) dp[n.n-1][n.b]=n.d+1,q.push({n.n-1,n.b,n.d+1});
    }
    cout << (dp[N-1][K]==1e18?-1:dp[N-1][K]) << "\n";
}
