/*
██████╗░░█████╗░██████╗░███████╗██╗░░░░░██╗░░░░░
██╔══██╗██╔══██╗██╔══██╗██╔════╝██║░░░░░██║░░░░░
██████╔╝██║░░██║██████╦╝█████╗░░██║░░░░░██║░░░░░
██╔══██╗██║░░██║██╔══██╗██╔══╝░░██║░░░░░██║░░░░░
██║░░██║╚█████╔╝██████╦╝███████╗███████╗███████╗
╚═╝░░╚═╝░╚════╝░╚═════╝░╚══════╝╚══════╝╚══════╝
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
const int MN = 1e5, MQ = 1e5;
int N, Q, X[MN], r[MQ];
vector<int> l[MN];
priority_queue<int> v[MN];
set<pair<int,int>> aq[MQ];
void dfs(int i, int p){
    v[i].push(X[i]);
    for (int& j:l[i]){
        if (j==p) continue;
        dfs(j,i);
    }
    for (int& j:l[i]){
        if (j==p) continue;
        while (!v[j].empty()){
            v[i].push(v[j].top());
            v[j].pop();
        }
    }
    priority_queue<int> temp;
    vector<int> ans;
    int s = 20;
    while ((s--)&&(!v[i].empty())){
        ans.pb(v[i].top());
        temp.push(v[i].top());v[i].pop();
    }
    swap(temp,v[i]);
    for (auto& q:aq[i]) r[q.s]=ans[q.f];
}
int main(){
	setIO();rv(N, Q);
    set<int> val;map<int,int> m, rm;
    for (int i=0;i<N;i++) rv(X[i]);
    for (int i=0;i<N-1;i++){
        int a, b;rv(a,b);
        l[--a].eb(--b);l[b].eb(a);
    }
    for (int s=0;s<Q;s++){
        int v, k;rv(v,k);
        aq[--v].insert({--k,s});
    }
    dfs(0,0);
    for (int i=0;i<Q;i++) cout << r[i] << "\n";
}
