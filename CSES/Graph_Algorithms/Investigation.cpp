/*
██████╗░░█████╗░██████╗░███████╗██╗░░░░░██╗░░░░░
██╔══██╗██╔══██╗██╔══██╗██╔════╝██║░░░░░██║░░░░░
██████╔╝██║░░██║██████╦╝█████╗░░██║░░░░░██║░░░░░
██╔══██╗██║░░██║██╔══██╗██╔══╝░░██║░░░░░██║░░░░░
██║░░██║╚█████╔╝██████╦╝███████╗███████╗███████╗
╚═╝░░╚═╝░╚════╝░╚═════╝░╚══════╝╚══════╝╚══════╝
Problem: Investigation
Problem Link: https://cses.fi/problemset/task/1202/
Notes: Djikstras with retention of a max and a min edge along with a reverse adjacency list.
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
    ll d;
    int ind, ct;
    bool operator<(const Edge &a) const{
        return (d>a.d);
    }
};
const int MN = 1e5;
int N, M;
vector<pair<int,ll>> l[MN];
vector<pair<int,ll>> rl[MN];
bool vis[MN];
ll minCost[MN], minCt[MN], minFl[MN], maxFl[MN];
priority_queue<Edge> pq;// distance, index, flights taken
int main(){
	setIO();rv(N, M);
    for (int i=0;i<M;i++){
        int a, b, c;rv(a,b,c);
        l[--a].pb({--b,c});
        rl[b].pb({a,c});
    }
    fill(minFl, minFl+N, 1e9);
    fill(minCost, minCost+N, 1e18);
    minCost[0]=0, minCt[0]=1, minFl[0]=0, maxFl[0]=0;
    Edge t = {0,0,0};
    pq.push(t);
    while (!pq.empty()){
        auto a = pq.top();pq.pop();
        if (minCost[a.ind]<a.d) continue;
        if (minFl[a.ind]<a.ct && maxFl[a.ind]>a.ct) continue;
        if (!vis[a.ind]){
            for (auto& j:rl[a.ind]){
                if (minCost[j.x]==minCost[a.ind]-j.y) (minCt[a.ind]+=minCt[j.x])%=mod;
            }
            vis[a.ind]=1;
        }
        for (auto& j:l[a.ind]){
            if (minCost[j.x]>a.d+j.y){
                minCost[j.x]=a.d+j.y;
                minFl[j.x]=a.ct+1;
                maxFl[j.x]=a.ct+1;
                pq.push({minCost[j.x], j.x, a.ct+1});
            }else if (minCost[j.x]==a.d+j.y){
                if ((minFl[j.x]>a.ct+1)||(maxFl[j.x]<a.ct+1)){
                    minFl[j.x]=min(minFl[j.x],(ll)a.ct+1);
                    maxFl[j.x]=max(maxFl[j.x],(ll)a.ct+1);
                    pq.push({minCost[j.x], j.x, a.ct+1});
                }
            }
        }
    }
    cout << minCost[N-1] << " " << minCt[N-1] << " " << minFl[N-1] << " " << maxFl[N-1] << "\n";
}
