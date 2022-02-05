/*
Problem: Farm Updates
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=1186
Notes: I should've realized in contest that the add query is p much useless if you process queries offline backwards
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
const int MQ = 2e5, MN = 1e5;
struct Query{char t;int x, y;};
struct Road{
    int x, y;
};
int N, Q, parent[MN], sizes[MN], res[MN], act[MN];
vector<int> under[MN];
Query q[MQ];
vector<Road> rs;
vector<bool> use;
int findparent(int i){
    if (i==parent[i]) return i;
    else{
        parent[i]=findparent(parent[i]);
        return parent[i];
    }
}
void unions(int u, int v){
    u=findparent(u);v=findparent(v);
    if (u==v) return;
    if (sizes[v]>sizes[u]) swap(u,v);
    sizes[u]+=sizes[v];act[u]+=act[v];
    parent[v]=u;
    for (int j:under[v]) under[u].eb(j);
}
int main(){
	setIO();cin >> N >> Q;
    for (int i=0;i<N;i++) act[i]=1,parent[i]=i, sizes[i]=1, under[i].pb(i);
    for (int i=0;i<Q;i++){
        cin >> q[i].t >> q[i].x;q[i].x--;
        if (q[i].t=='A'){
            cin >> q[i].y;q[i].y--;
        }
    }
    for (int i=0;i<Q;i++){
        if (q[i].t=='D'){
            int par = findparent(q[i].x);
            act[par]--;
        }else if (q[i].t=='A'){
            rs.pb({q[i].x,q[i].y});use.pb(1);
        }else use[q[i].x]=0;
    }
    for (int i=0;i<rs.size();i++) if (use[i]) unions(rs[i].x,rs[i].y);
    set<int> pars;
    for (int i=0;i<N;i++){
        int ind = findparent(i);
        if (pars.find(ind)==pars.end()){
            pars.insert(ind);
            if (act[ind]>0){
                for (int j=0;j<under[ind].size();j++) res[under[ind][j]]=Q;
            }
        }
    }
    for (int i=Q-1;i>=0;i--){
        if (q[i].t=='A') continue;
        else if (q[i].t=='D'){
            int ind = findparent(q[i].x);
            if (act[ind]==0) for (int j:under[ind]) res[j]=i;
            act[ind]++;
        }else{
            int x = rs[q[i].x].x, y = rs[q[i].x].y;
            x=findparent(x);y=findparent(y);
            if (x==y) continue;
            if (act[x]==0 && act[y]>0){
                for (int j=0;j<under[x].size();j++) res[under[x][j]]=i;
            }
            if (act[y]==0 && act[x]>0){
                for (int j=0;j<under[y].size();j++) res[under[y][j]]=i;
            }
            unions(x,y);
        }
    }
    for (int i=0;i<N;i++) cout << res[i] << "\n";
}
