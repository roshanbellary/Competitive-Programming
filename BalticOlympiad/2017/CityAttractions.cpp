/*
Problem: City Attractions
Problem Link: https://csacademy.com/contest/virtual8509/task/city-attractions/
Notes: Hard part was figuring out how to take information from outside of subtree to determine min distance
and secondary hard part was figuring out I just had to make a pseudo lca to find node K steps away.
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
const int MN = 3e5;
ll K;
int N, a[MN], dp[MN][60];
vector<int> l[MN];
pair<int,int> mv[MN], subt[MN], out[MN];
void dfs(int ind, int p){
    for (int j:l[ind]){
        if (j==p) continue;
        dfs(j,ind);
        subt[ind]=min({make_pair(subt[j].f+1,subt[j].s),{1-a[j],j},subt[ind]});
    }
}
void dfs2(int ind, int p){
    subt[ind] = min(subt[ind], out[ind]);
	pair<int, int> comp = {1+out[ind].first, out[ind].second};
	comp = min(comp, {1-a[ind], ind});
	for (int i : l[ind]){ 
        if (i != p) {
		    out[i] = min(out[i], comp);
		    comp = min({comp, {subt[i].first+2, subt[i].second}, {a[i]+2, i}});
	    }
    }
	reverse(l[ind].begin(), l[ind].end());
	comp = {out[ind].first+1, out[ind].second};
	comp = min(comp, {a[ind]+1, ind});
	for (int i : l[ind]) if (i != p) {
		out[i] = min(out[i], comp);
		comp = min({comp, {subt[i].first+2, subt[i].second}, {a[i]+2, i}});
	}
	for (int i : l[ind]) if (i != p) dfs2(i, ind);
}
int main(){
	setIO();rv(N, K);
    for (int i=0;i<N;i++) rv(a[i]);
    for (int i=0;i<N-1;i++){
        int u, v; rv(u,v);
        l[--u].eb(--v);l[v].eb(u);
        out[i]={-5e8,0};
    }
    dfs(0,0);dfs2(0,0);
    for (int i=0;i<N;i++){dp[i][0]=subt[i].s;}
    for (int k=1;k<60;k++){
        for (int i=0;i<N;i++){
            dp[i][k]=dp[dp[i][k-1]][k-1];
        }
    }
    int ind = 0;
    for (int i=60;i>=0;i--){
        if ((K&(1LL<<i))!=0) ind=dp[ind][i];
    }
    cout << ind+1 << "\n";
}
