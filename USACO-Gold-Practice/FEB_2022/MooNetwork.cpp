/*
██████╗░░█████╗░██████╗░███████╗██╗░░░░░██╗░░░░░
██╔══██╗██╔══██╗██╔══██╗██╔════╝██║░░░░░██║░░░░░
██████╔╝██║░░██║██████╦╝█████╗░░██║░░░░░██║░░░░░
██╔══██╗██║░░██║██╔══██╗██╔══╝░░██║░░░░░██║░░░░░
██║░░██║╚█████╔╝██████╦╝███████╗███████╗███████╗
╚═╝░░╚═╝░╚════╝░╚═════╝░╚══════╝╚══════╝╚══════╝
Problem: Moo Network
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=1211
Notes: MST Problem where you minimize the number of edges you consider at a point
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
    ll i, j, d;
    bool operator<(const Edge& a) const {
        return (d>a.d);
    }
};
const int MN = 1e5, MY = 11;
int N, cl[MY], par[MN], sizes[MN];
pair<ll,ll> p[MN];
priority_queue<Edge> pq;
ll return_dist(int i, int j){
    return (pow(p[i].x-p[j].x,2)+pow(p[i].y-p[j].y,2));
}
int findroot(int i){
    if (i==par[i]) return i;
    else{
        par[i]=findroot(par[i]);
        return par[i];
    }
}
void unions(int i, int j){
    i=findroot(i);j=findroot(j);
    if (i==j) return;
    if (sizes[j]>sizes[i]) swap(i,j);
    sizes[i]+=sizes[j];par[j]=i;
}
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++) rv(p[i].x,p[i].y);
    fill(sizes,sizes+N,1);
    sort(p,p+N);
    for (int i=0;i<N;i++) par[i]=i;
    fill(cl,cl+MY,-1);
    for (int i=0;i<N;i++){
        for (int j=0;j<=10;j++) if (cl[j]>=0) pq.push({i,cl[j],return_dist(i,cl[j])});
        cl[p[i].y]=i;
    }
    ll res = 0;
    while (!pq.empty()){
        Edge a=pq.top();pq.pop();
        a.i=findroot(a.i);a.j=findroot(a.j);
        if (a.i!=a.j){
            unions(a.i,a.j);
            res+=a.d;
        }
    }
    cout << res << "\n";
}
