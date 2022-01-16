/*
Problem: At Large
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=790
Notes: BFS Sol
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
const int MN = 1e5;
int N, K, d[MN], df[MN], res=0;
bool w = 1;
vector<int> l[MN];
queue<pair<int,int>> q;
void dfs(int i, int p){
    if (d[i]>=df[i]){res++; return;}
    else if (d[i]<df[i] && i!=K && l[i].size()==1) w=0;
    for (int& j:l[i]){
        if (j==p) continue;
        dfs(j,i);
    }
}
int main(){
	setIO("atlarge");rv(N, K);K--;
    for (int i=0;i<N;i++) d[i]=df[i]=1e9;
    for (int i=0;i<N-1;i++){
        int u, v; rv(u,v);
        l[--u].eb(--v);
        l[v].eb(u);
    }
    d[K]=0;q.push({K,0});
    while (!q.empty()){
        auto a = q.front();q.pop();
        if (d[a.f]<a.s) continue;
        for (int& j:l[a.f]){
            if (d[j]>a.s+1){
                d[j]=a.s+1;
                q.push({j,d[j]});
            }
        }
    }
    for (int i=0;i<N;i++){
        if (l[i].size()==1 && i!=K){
            df[i]=0;q.push({i,0});
        }
    }
    while (!q.empty()){
        auto a = q.front();q.pop();
        if (df[a.f]<a.s) continue;
        for (int& j:l[a.f]){
            if (df[j]>a.s+1){
                df[j]=a.s+1;
                q.push({j,df[j]});
            }
        }
    }
    dfs(K,K);cout << (w?res:(-1)) << "\n";
}
