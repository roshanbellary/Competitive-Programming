/*
Problem: Galaksija
Problem Link: https://dmoj.ca/problem/coci15c4p5
Notes: Cool dsu prob think about how to combine connected components
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
struct Edge{
    int u, v, m;
};
const int MN = 1e5;
int N, parent[MN], sizes[MN], cval[MN], order[MN];
ll pairs = 0;
vector<Edge> edges;
vector<set<int>> under;
multiset<pair<ll,ll>> m[MN];
vector<ll> res;
int findparent(int u){
    if (parent[u]==u) return u;
    else{
        parent[u]=findparent(parent[u]);
        return parent[u];
    }
}
void unions(int u, int v, ll val){
    ll cu = cval[u], cv = cval[v];
    u=findparent(u);v=findparent(v);
    if (sizes[v]>sizes[u]) swap(u,v);
    for (auto a:under[v]) cval[a]=(cval[a]^cv^val^cu),under[u].insert(a);
    for (auto a:m[v]){
        ll nv = a.f^cu^cv^val;
        auto itr = m[u].upper_bound({nv,0});
        if (itr==m[u].end()){
            m[u].insert({nv,a.s});
        }else if (itr->first==nv){
            ll c = itr->second;
            pairs+=(c*a.s);c+=a.s;
            m[u].erase(itr);m[u].insert({nv,c});
        }else m[u].insert({nv,a.s});
    }
    parent[v]=u;sizes[u]+=sizes[v];
}
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++) under.pb(set<int>());
    for (int i=0;i<N;i++) parent[i]=i,sizes[i]=1,under[i].insert(i),m[i].insert({0,1});
    for (int i=0;i<N-1;i++){
        int a, b, z;rv(a,b,z);
        edges.pb({--a,--b,z});
    }
    for (int i=0;i<N-1;i++) rv(order[i]), order[i]--;
    for (int i=N-2;i>=0;i--){
        res.pb(pairs);
        unions(edges[order[i]].u,edges[order[i]].v,edges[order[i]].m);
    }
    res.pb(pairs);
    reverse(res.begin(),res.end());
    for (ll j:res) cout << j << "\n";
}
