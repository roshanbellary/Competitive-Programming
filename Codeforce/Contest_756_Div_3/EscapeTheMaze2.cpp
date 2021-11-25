/*
Problem: Escape The Maze (hard version)
Problem Link: https://codeforces.com/contest/1611/problem/E2
Notes: Not Finished
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
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar();
        for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar();
        for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(string &w){
    w="";char c=getchar();
    while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar();}
}
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
int T, N, K, x[(int)2e5], dy[(int)2e5],df[(int)2e5], lcd[(int)2e5][19];
vector<int> l[(int)2e5];
void dfs(int ind, int d){dy[ind]=d++;for (int j:l[ind]) dfs(j,d), lcd[j][0]=ind;}
void mlca(){for (int j=0;j<log(N);j++) for (int i=0;i<N;i++) lcd[i][j+1]=lcd[lcd[i][j]][j];}
int lca(int i, int j){
    if (dy[i]<dy[j]) swap(i,j);
    int diff = dy[j]-dy[i];
    for (int k=0;k<=log2(N);k++) if (diff&(1<<k)) j=lcd[j][k];
    if (i==j) return i;
    for (int k=log2(N)-1;k>=0;k--){
        if (lcd[i][k]!=lcd[j][k]) i=lcd[i][k],j=lcd[j][k];
    }
    return lcd[i][0];
}
void solve(){
    for (int i=0;i<K;i++) cin >> x[i],x[i]--;
    for (int i=0;i<N-1;i++){
        int u, v; cin >> u >> v;u--;v--;
        l[u].pb(v);l[v].pb(u);
    }
    dfs(0,0);mlca();
}
int main(){
	setIO();cin >> T;
    while (T--){
        cin >> N >> K;
        for (int i=0;i<N;i++) l[i].clear(),dy[i]=1e9,df[i]=1e9;
        for (int i=0;i<N;i++) for (int j=0;j<=log2(N)+1;j++) lcd[i][j]=i;
        solve();
    }
}
