/*
Problem: Tug
Problem Link: https://oj.uz/problem/view/BOI15_tug
Notes: Had to look at editorial cool bitset and graph prob
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
const int MX = 300000;
int N, K; multiset<pair<int,int>> adj[2 * MX]; int tot; bool vis[2 * MX]; vector<int> todo;
queue<int> q; 
void dfs(int X) {
    vis[X] = true; pair<int,int> edge = *adj[X].begin();
    tot += edge.s; if (!vis[edge.f]) { adj[X].clear(); adj[edge.f].erase(adj[edge.f].find({X, -edge.s})); dfs(edge.f); }
}
int main(){
	setIO();rv(N);
    rv(N,K); for (int i=0;i<2*N;i++){ 
        int a, b, S; rv(a,b,S); 
        adj[a].insert({N + b, S}), adj[N + b].insert({a, -S});
    }
    for (int i=1;i<=2*N;i++) { 
        if (adj[i].size()==0){cout<<"NO\n";return 0;} 
        if (adj[i].size()==1) q.push(i);
    }
    while (!q.empty()) {
        int cur=q.front();q.pop();if (adj[cur].size() == 0) { cout << "NO\n"; return 0; }
        pair<int,int> res = *adj[cur].rbegin(); tot += res.s; adj[cur].clear(); adj[res.f].erase(adj[res.f].find({cur, -res.s}));
        if (adj[res.f].size() == 1) q.push(res.f);
    }
    if (tot) todo.pb(abs(tot)); for (int i=1;i<=2*N;i++) if (!vis[i] && adj[i].size()) {
        tot = 0; adj[i].erase(adj[i].begin()); dfs(i); if (tot) todo.pb(abs(tot));
    }
    bitset<40 * MX> DP; DP[20 * MX] = 1;for (auto C:todo) DP = (DP << C) | (DP >> C);
    for (int i=20*MX-K;i<=20*MX+K;i++)  if (DP[i]) { cout << "YES\n"; return 0; } cout << "NO\n";
}
