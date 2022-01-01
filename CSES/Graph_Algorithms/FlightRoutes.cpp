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
const int MN = 1e5;
int N, M, K;
ll dp[MN][10];
vector<pair<int,ll>> l[MN];
priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>> pq;
int find(int i, ll v){
    int s=0, f=K-1;
    while (s!=f){
        int mid = (s+f)/2;
        if (dp[i][mid]>v) f=mid;
        else s=mid+1;
    }
    if (dp[i][s]>v) return s;
    else return (-1);
}
int main(){
	setIO();rv(N, M, K);
    for (int i=0;i<N;i++) for (int j=0;j<K;j++) dp[i][j]=1e18;
    while (M--){
        int a, b; ll c;
        rv(a,b,c);l[--a].pb({--b,c});
    }
    pq.push({0,{0,0}});dp[0][0]=0;
    while (!pq.empty()){
        auto a = pq.top();pq.pop();
        if (dp[a.s.f][K-1]<a.f) continue;
        for (auto& b:l[a.s.f]){
            ll d = a.f+b.s;int ind = find(b.f,d);
            if (ind!=-1){
                ll dist = d;pq.push({dist,{b.f,ind}});
                while (ind<K){
                    ll t = dp[b.f][ind];
                    dp[b.f][ind]=d;
                    d=t;ind++;
                }
            }
        }
    }
    for (int i=0;i<K;i++) cout << dp[N-1][i] << " ";
    cout << "\n";
}