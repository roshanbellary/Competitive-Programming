/*
██████╗░░█████╗░██████╗░███████╗██╗░░░░░██╗░░░░░
██╔══██╗██╔══██╗██╔══██╗██╔════╝██║░░░░░██║░░░░░
██████╔╝██║░░██║██████╦╝█████╗░░██║░░░░░██║░░░░░
██╔══██╗██║░░██║██╔══██╗██╔══╝░░██║░░░░░██║░░░░░
██║░░██║╚█████╔╝██████╦╝███████╗███████╗███████╗
╚═╝░░╚═╝░╚════╝░╚═════╝░╚══════╝╚══════╝╚══════╝
Problem: Road Reparation
Problem Link: https://cses.fi/problemset/task/1675
Notes: 
In essence making a minimum spanning tree, I just used disjoint set union with optimizations
to count how many existing CCs exist until the alg reaches 1.
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
#define x first
#define y second
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
inline void rv(char &c){c=' ';while (c==' '|| c=='\n' || c==EOF) c=getchar();}
template<typename T, typename ...Types>
inline void rv(T &n, Types&&... args){rv(n);rv(args...);}
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
    ll a, b, c;
    bool operator<(const Edge &a) const{
        return (c>a.c);
    }
};
const int MN = 1e5;
int N, M, par[MN], sizes[MN], comps;
priority_queue<Edge> pq;
int findpar(int i){
    if (i==par[i]) return i;
    else{
        par[i]=findpar(par[i]);
        return par[i];
    }
}
void unions(int a, int b){
    a=findpar(a);b=findpar(b);
    if (a==b) return;
    if (sizes[b]>sizes[a]) swap(a,b);
    sizes[a]+=sizes[b];
    par[b]=a;
}
int main(){
	setIO();rv(N, M);comps=N;
    for (int i=0;i<N;i++) par[i]=i;
    while (M--){
        int a, b, c;rv(a,b,c);a--;b--;
        pq.push({a,b,c});
    }
    ll res = 0;
    while (!pq.empty() && comps){
        Edge v = pq.top();pq.pop();
        v.a=findpar(v.a);
        v.b=findpar(v.b);
        if (v.a==v.b) continue;
        res+=v.c;
        unions(v.a,v.b); comps--;
    }
    cout << (comps==1?to_string(res):"IMPOSSIBLE") << "\n";
}
