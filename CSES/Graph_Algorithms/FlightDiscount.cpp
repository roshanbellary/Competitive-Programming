/*
Problem:Flight Discount 
Problem Link: https://cses.fi/problemset/task/1195
Notes: Djikstra Problem where you also store the state of whether or not you have used the half length
flight or not.
*/
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
struct Event{
    ll d;ll ind;bool u;
    bool operator<(const Event &n) const{return (n.d<d);}
};
ll N, M, dp[(int)1e5][2];
vector<pair<ll,ll>> l[(int)1e5];
priority_queue<Event> pq;
void setDist(){
    for (int i=0;i<N;i++) dp[i][0]=dp[i][1]=1e18;
}
int main(){
	setIO();rv(N, M);setDist();
    for (int i=0;i<M;i++){
        ll a, b, c;rv(a,b,c);a--;b--;
        l[a].pb({b,c});
    }
    dp[0][0]=0;
    pq.push({0,0,0});
    while (!pq.empty()){
        Event n = pq.top();pq.pop();
        if (dp[n.ind][n.u]<n.d) continue;
        for (auto &a:l[n.ind]){
            if (dp[a.f][n.u]>dp[n.ind][n.u]+a.s){
                dp[a.f][n.u]=dp[n.ind][n.u]+a.s;
                pq.push({dp[n.ind][n.u]+a.s,a.f,n.u});
            }
            if (!n.u){
                if (dp[a.f][1]>dp[n.ind][0]+a.s/2){
                    dp[a.f][1]=dp[n.ind][0]+a.s/2;
                    pq.push({dp[n.ind][0]+a.s/2,a.f,1});
                }
            }
        }
    }
    cout << dp[N-1][1] << "\n";
}
