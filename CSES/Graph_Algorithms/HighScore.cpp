/*
Problem: High Score
Problem Link: https://cses.fi/problemset/task/1673/
Notes: Hard problem.
First you can use Bellman Ford for N-1 iterations and note down the maximum distance.
From there you need to determine if there exists a maximum cycle in the path from 1 to N
(Note: if there is a maximal cycle but it's not on a path from 1 to N then it doesn't matter)
We can find the cycle doing another iteration of bellman ford and noting which vertex distances increased
From there we can dfs from node N using a reverse adjacency list and see if any path from N hits a node on a maximal cycle if so
then we print -1 if not then we print out the maximum distance
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
struct Edge{
    ll f,s,x;
};
ll N, M, d[(int)2500];
bool cyc[(int)2500],v[(int)2500],w=0;
vector<Edge> l;
vector<int> rl[(int)2500];
void dfs(int ind){
    if (w) return;
    v[ind]=1;if (cyc[ind]){w=1;return;}
    for (int j:rl[ind]){
        if (!v[j]) dfs(j);
    }
}
int main(){
	setIO();
    rv(N, M);
    for (int i=0;i<M;i++){
        int a, b, x; rv(a,b,x);a--;b--;
        l.pb({a,b,x});
        rl[b].pb(a);
    }
    for (int i=0;i<2500;i++) d[i]=-1e18;
    d[0]=0;
    int st = N-1;
    while (st--){
        for (Edge &e:l){
            if (d[e.f]!=(-1e18)){
                d[e.s]=max(d[e.f]+e.x,d[e.s]);
            }
        }
    }
    for (Edge &e:l){
        if (d[e.f]!=(-1e18)){
            if (d[e.s]<d[e.f]+e.x){
                cyc[e.s]=1;
            }
        }
    }
    dfs(N-1);
    cout << (w?-1:d[N-1]) << "\n";
}
