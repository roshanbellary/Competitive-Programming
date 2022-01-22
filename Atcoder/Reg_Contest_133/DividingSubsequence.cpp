/*
Problem: Dividing Subsequence
Problem Link: https://atcoder.jp/contests/arc133/tasks/arc133_b
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
const int MN = 2e5+1;
int N, p[MN], q[MN], pos[MN], st[4*MN], dp[MN];
vector<int> mul[MN];
void build(int node, int s, int f){
    if (s==f) st[node]=dp[s];
    else{
        build(2*node,s,(s+f)/2);
        build(2*node+1,(s+f)/2+1,f);
        st[node]=max(st[2*node],st[2*node+1]);
    }
}
void update(int node, int s, int f, int p, int v){
    if (f<p || s>p) return;
    if (s==f) st[node]=v;
    else{
        update(2*node,s,(s+f)/2,p,v);
        update(2*node+1,(s+f)/2+1,f,p,v);
        st[node]=max(st[2*node],st[2*node+1]);
    }
}
int query(int node, int s, int f, int qs, int qf){
    if (f<qs || s>qf) return 0;
    if (s>=qs && f<=qf) return st[node];
    return max(query(2*node,s,(s+f)/2,qs,qf),query(2*node+1,(s+f)/2+1,f,qs,qf));
}
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++) rv(p[i]);
    for (int i=0;i<N;i++) rv(q[i]);
    for (int i=0;i<N;i++) pos[q[i]-1]=i;
    for (int i=1;i<=N;i++){
        for (int k=i;k<=N;k+=i){
            mul[i-1].pb(pos[k-1]);
        }
        sort(mul[i-1].begin(),mul[i-1].end());
    }
    build(1,0,N-1);
    for (int i=0;i<N;i++){
        for (int& k:mul[p[i]-1]){
            dp[k]=max(dp[k],1);
            int mv = 0;
            if (k!=0) mv = query(1,0,N-1,0,k-1);
            dp[k]=max(mv+1,dp[k]);
        }
        for (int& k:mul[p[i]-1]) update(1,0,N-1,k,dp[k]);
    }
    int mv = 0;
    for (int i=0;i<N;i++) mv=max(mv,dp[i]);
    cout << mv << "\n";
}
