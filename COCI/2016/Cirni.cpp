/*
Problem: 
Problem Link: 
Notes: 
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
    ll u, v, val;
    bool operator<(const Edge& a) const {return (val>a.val);}
};
const int MN = 1e5;
ll N,v[MN];
int parent[MN], sizes[MN];
priority_queue<Edge> pq;
ll find(ll val){
    int s = 0, f=N-1;
    while (s!=f){
        int mid=(s+f)/2;
        if (v[mid]>=val) f=mid;
        else s=mid+1;
    }
    if (v[s]>=val) return s;
    else return (-1);
}
int findparent(int i){
    if (parent[i]==i) return i;
    else{parent[i]=findparent(parent[i]);return parent[i];}
}
void unions(int u, int v){
    if (sizes[v]>sizes[u]) swap(u,v);
    parent[v]=u;sizes[u]+=sizes[v];
}
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++) rv(v[i]),parent[i]=i, sizes[i]=1;
    sort(v,v+N);ll maxv = *max_element(v,v+N);
    for (int i=0;i<N;i++){
        for (int j=1;j<=(maxv/v[i]);j++){
            int ind = find(v[i]*j);
            if (ind==-1) break;
            for (int k=ind;k<N;k++){
                if (v[k]==v[ind]) pq.push({i,k,v[k]%v[i]});
                else break;
            }
        }
    }
    ll res = 0;
    while (!pq.empty()){
        Edge t = pq.top();pq.pop();
        t.u=findparent(t.u);t.v=findparent(t.v);
        if (t.u==t.v) continue;
        res+=t.val;unions(t.u,t.v);
    }
    cout << res << "\n";
}
