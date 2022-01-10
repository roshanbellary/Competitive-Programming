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
const int MN = 2e5;
int T, N, K, r[MN], d[MN], num = 0;
vector<int> l[MN];
queue<pair<int,int>> q;
bool esc = 0;
void dfs(int i, int p, int dist){
    if (dist>=d[i]){num++;return;}
    else if (l[i].size()==1 && i!=0){esc=1;return;}
    int dist2=dist+1;
    for (int& j:l[i]){
        if (j==p) continue;
        dfs(j,p,dist2);
    }
}
void solve(){
    cin >> N >> K;esc=0,num=0;
    for (int i=0;i<K;++i) cin >> r[i], r[i]--;
    for (int i=0;i<N;++i) l[i].clear(), d[i]=1e9;
    for (int i=0;i<N-1;++i){
        int u, v; cin >> u >> v;l[--u].eb(--v);l[v].eb(u);
    }
    for (int i=0;i<K;++i) d[r[i]]=0, q.push({r[i],0});
    while (!q.empty()){
        auto a = q.front();q.pop();
        if (d[a.f]<a.s) continue;
        for (int& j:l[a.f]){
            if (d[j]>a.s+1) d[j]=a.s+1, q.push({j,d[j]});
        }
    }
    dfs(0,0,0);
    if (esc) cout << "-1\n";
    else cout << num << "\n";
}
int main(){
    cin >> T;while (T--) solve();
}
