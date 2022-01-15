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
const int MN = 1e4, MM = 5e4;
ll N, M, T, c[MN], d[MN], nsub[MN];
vector<pair<int,ll>> l[MN];
ll maxv=0;
priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> q;
vector<int> nl[MN];
bool v[MN];
ll dfs(int i){
    ll v = c[i];
    for (int& a:nl[i]) v+=dfs(a);
    maxv=max(maxv,(d[i]-T)*v);
    return v;
}
int main(){
	setIO("shortcut");rv(N, M, T);
    for (int i=0;i<N;i++) rv(c[i]), d[i]=1e9;
    for (int i=0;i<M;i++){
        int a, b, t; rv(a,b,t);
        l[--a].pb({--b,t});
        l[b].pb({a,t});
    }
    d[0]=0;q.push({0,0});
    while (!q.empty()){
        auto a = q.top();q.pop();
        if (d[a.s]<a.f) continue;
        for (auto& e:l[a.s]){
            if (d[e.f]>e.s+a.f){
                d[e.f]=e.s+a.f;
                q.push({e.s+a.f,e.f});
            }
        }
    }
    for (int i=0;i<N;i++) sort(l[i].begin(),l[i].end());
    for (int i=1;i<N;i++){
        for (auto &a:l[i]){
            if (d[a.f]+a.s==d[i]){
                nl[a.f].pb(i);break;
            }
        }
    }
    dfs(0);
    cout << maxv << "\n";
}
