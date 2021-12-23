/*
Problem: Hotel Queries
Problem Link: https://cses.fi/problemset/task/1143/
Notes: 
I solved this using a range maximum segment tree that supports updates then binary searching
for the earliest index for which the maximum from the first index to it is greater than the size of the group
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
const int MN = 8e5;
const int MA = 2e5;
int N, M, st[MN],v[MA];
void build(int node, int s, int f){
    if (s==f){st[node]=v[s];}
    else{
        build(2*node,s,(s+f)/2);
        build(2*node+1,(s+f)/2+1,f);
        st[node]=max(st[2*node],st[2*node+1]);
    }
}
void update(int node, int s, int f, int ind, int val){
    if (s==f) v[ind]=val,st[node]=val;
    else{
        if (s<=ind && ind<=(s+f)/2) update(2*node,s,(s+f)/2,ind,val);
        if ((s+f)/2+1<=ind && ind<=f) update(2*node+1,(s+f)/2+1,f,ind,val);
        st[node]=max(st[2*node],st[2*node+1]);
    }
}
int query(int node, int qs, int qf, int s, int f){
    if (f<qs || s>qf) return -1;
    if (s>=qs && f<=qf) return st[node];
    return max(query(2*node,qs,qf,s,(s+f)/2),query(2*node+1,qs,qf,(s+f)/2+1,f));
}
int main(){
	setIO();rv(N, M);
    for (int i=0;i<N;i++) rv(v[i]);
    build(1,0,N-1);
    while (M--){
        int n; rv(n);
        int s = 0, f=N-1;
        while (s!=f){
            int mid = (s+f)/2;
            if (n<=query(1,0,mid,0,N-1)) f=mid;
            else s=mid+1;
        }
        if (n<=query(1,0,s,0,N-1)){cout << s+1 << " ";update(1,0,N-1,s,v[s]-n);}
        else cout << "0 ";
    }
    cout << "\n";
}
