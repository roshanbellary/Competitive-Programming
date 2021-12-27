/*
Problem: Tree Distances I
Problem Link: https://cses.fi/problemset/task/1132/
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
const int MN = 2e5;
int N, dps[MN][2], dpa[MN];
vector<int> l[MN];
void dfs1(int ind, int p){
    dps[ind][0]=dps[ind][1]=0;
    priority_queue<int> pq;
    for (int& j:l[ind]){
        if (j==p) continue;
        dfs1(j,ind);pq.push(dps[j][0]+1);
    }
    for (int i=0;i<2;i++){
        if (!pq.empty()) dps[ind][i]=pq.top(),pq.pop();
    }
}
void dfs2(int ind, int p, int d){
    for (int& j:l[ind]){
        if (j==p) continue;
        if (dps[j][0]==dps[ind][0]-1) dpa[j]=max(dps[ind][1]+1,d+1);
        else dpa[j]=max(dps[ind][0]+1,d+1);
        dfs2(j,ind,dpa[j]);
    }
}
int main(){
	setIO();rv(N);
    for (int i=0;i<N-1;i++){
        int u, v;rv(u,v);
        l[--u].eb(--v);
        l[v].eb(u);
    }
    dfs1(0,0);dfs2(0,0,0);
    for (int i=0;i<N;i++) cout << max(dps[i][0],dpa[i]) << " ";
    cout << "\n";
}
