/*
Problem: Cycle Finding
Problem Link: https://cses.fi/problemset/task/1197/
Notes: Floyd Warshall Alg p much
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
    ll a, b, c;
};
ll N, M, d[2500], ch[2500];
vector<Edge> l;
vector<pair<ll,ll>> li[2500];
vector<int> ind;set<int> nodes;
bool cyc = 0;
int fo = 0;
void dfs(int i){
    ind.pb(i);nodes.insert(i);
    i=ch[i];
    if (nodes.find(i)!=nodes.end()){ind.pb(i);return;}
    else dfs(i);
}
int main(){
	setIO();rv(N, M);for (int i=0;i<N;i++) d[i]=0;
    for (ll i=0;i<M;i++){
        ll a, b, c; rv(a,b,c);a--;b--;
        l.pb({a,b,c});ch[a]=a;
        li[a].pb({b,c});
    }
    ll st = N-1;fo=-1;
    while (st--){
        for (auto &a:l){
            if (d[a.b]>d[a.a]+a.c){
                ch[a.b]=a.a;d[a.b]=d[a.a]+a.c;
            }
        }
    }
    for (auto &a:l) if (d[a.b]>d[a.a]+a.c){
        ch[a.b]=a.a;d[a.b]=d[a.a]+a.c;fo=a.b;cyc=1;break;
    }
    if (!cyc){cout << "NO\n";return 0;}
    cout << "YES\n";
    dfs(fo);cout << ind.back()+1 << " ";
    for (int i=ind.size()-2;i>=0;i--){
         cout << ind[i]+1 << " ";
        if (ind[i]==ind.back()) break;
    }
    cout << "\n";
}
