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
const int MN = 2e5+1;
const int MS = 8e5+1;
int N, Q, p[MN];
pair<int,int> st[MS];
void build(int node, int s, int f){
    if (s==f) st[node]={p[s]-s,p[s]+s};
    else{
        build(2*node,s,(s+f)/2);
        build(2*node+1,(s+f)/2+1,f);
        st[node]={min(st[2*node].f,st[2*node+1].f),min(st[2*node].s,st[2*node+1].s)};
    }
}
void update(int node, int s, int f, int ind, int v){
    if (f<ind || s>ind) return;
    else if (s==f) st[node]={v-s,v+s};
    else{
        update(2*node,s,(s+f)/2,ind,v);
        update(2*node+1,(s+f)/2+1,f,ind,v);
        st[node]={min(st[2*node].f,st[2*node+1].f),min(st[2*node].s,st[2*node+1].s)};
    }
}
int queryf(int node, int s, int f, int ind){
    if (s>=ind) return 2e9;
    else if (f<ind) return st[node].f;
    else return min(queryf(2*node,s,(s+f)/2,ind),queryf(2*node+1,(s+f)/2+1,f,ind));
}
int querys(int node, int s, int f, int ind){
    if (f<=ind) return 2e9;
    else if (s>ind) return st[node].s;
    else return min(querys(2*node,s,(s+f)/2,ind),querys(2*node+1,(s+f)/2+1,f,ind));
}
int main(){
	setIO();rv(N, Q);
    for (int i=1;i<=N;i++) rv(p[i]);
    build(1,1,N);
    while (Q--){
        int t, k; rv(t,k);
        if (t==1){int x; rv(x);update(1,1,N,k,x);p[k]=x;}
        else cout << min({queryf(1,1,N,k)+k, querys(1,1,N,k)-k,p[k]}) << "\n";
    }
}
