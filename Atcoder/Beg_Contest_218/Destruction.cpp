/*
Problem: Destruction
Problem Link: https://atcoder.jp/contests/abc218/tasks/abc218_e
Notes: 
Any problem involving connected components is probably a DSU prob which it turns out it is.
For any negative edges you immediately link the two vertices together since you're never going to destroy a negative edge.
Now we take the positive edges. We first rank the positive edges from smallest to largest.
For a positive edge if the two vertices are in the same connected component you add its value to the collected value as you don't need
it to create connectivity. For an edge that has two vertices in different components you disregard it and connect the two components.
Finally when the number of connected components reaches 0 you take the remaining edges and add their values to your collected value.

Proof for why this works:

After the negative edges are added, you have a distinct set of connected components.
Between two connected components there is going to be a set of positive edges that connect them together.
Taking the minimmum of that set and not using it is the most optimal method which is what we do when we order the edges by smallest to largest
and iterate through them.
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
    int u, v, d;
    bool operator<(const Edge &n) const{
        return (d>n.d);
    }
};
int N, M, parent[(int)2e5], sizes[(int)2e5];
ll colD = 0;
priority_queue<Edge> pq;
set<int> comps;
bool v[(int)2e5];
int findparent(int i){
    if (parent[i]==i) return i;
    else{
        parent[i]=findparent(parent[i]);
        return parent[i];
    }
}
void unions(int u, int v){
    u=findparent(u);v=findparent(v);
    if (u==v) return;
    if (sizes[v]>sizes[u]) swap(u,v);
    parent[v]=u;sizes[u]+=sizes[v];
}
int main(){
	setIO();rv(N, M);
    for (int i=0;i<N;i++){sizes[i]=1;parent[i]=i;}
    for (int i=0;i<M;i++){
        int a, b, c;rv(a,b,c);a--;b--;
        if (c<=0){
            unions(a,b);
        }else{
            pq.push({a,b,c});
        }
    }
    for (int i=0;i<N;i++) comps.insert(findparent(i));
    int num = comps.size();
    while (num>1){
        Edge t = pq.top();pq.pop();
        int u, v;
        u=findparent(t.u);v=findparent(t.v);
        if (u==v) colD+=t.d;
        else{unions(u,v);num--;}
    }
    while (pq.size()>0){
        Edge t = pq.top();pq.pop();
        colD+=t.d;
    }
    cout << colD << "\n";
}
