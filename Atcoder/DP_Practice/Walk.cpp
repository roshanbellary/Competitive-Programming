/*
Problem: Walk
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_r
Notes: I used Matrix Exponenentiation although this is a dp prob so there might be a cool dp sol too
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
ll N, K;
vector<vector<ll>> dp(50,vector<ll>(50,0));
vector<vector<ll>> mult(vector<vector<ll>>& m1, vector<vector<ll>>& m2){
    vector<vector<ll>> res(m1.size(),vector<ll>(m1.size(),0));
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            for (int k=0;k<N;k++){
                (res[i][j]+=((((m1[i][k])%mod)*((m2[k][j])%mod))%mod))%=mod;
            }
        }
    }
    return res;
}
vector<vector<ll>> square(vector<vector<ll>>& m){
    vector<vector<ll>> m1=m, m2=m;
    return mult(m1,m2);
}
vector<vector<ll>> pow(ll power, vector<vector<ll>> p){
    if (power==1) return p;
    else if (power%2==0){
        vector<vector<ll>> res = pow(power/2,p);
        res=square(res);return res;
    }else{
        vector<vector<ll>> res = pow(power/2,p);
        res=square(res);return (mult(res,p));
    }
}
int main(){
	setIO();rv(N, K);
    for (int i=0;i<N;i++) for (int j=0;j<N;j++){int v; rv(v);dp[i][j]=(v==1);}
    vector<vector<ll>> ndp(N,vector<ll>(N,0));
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) if (dp[i][j]) ndp[j][i]=1;
    ndp=pow(K,ndp);
    ll res = 0;
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) (res+=(ndp[i][j]))%=mod;
    cout << res << "\n";
}
