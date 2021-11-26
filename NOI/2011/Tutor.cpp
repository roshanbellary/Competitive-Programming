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
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar_unlocked();
        for (;c>47 && c<58;c=getchar_unlocked()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar_unlocked();
        for (;c>47 && c<58;c=getchar_unlocked()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(string &w){
    w="";char c=getchar_unlocked();
    while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar_unlocked();}
}
inline void rv(char &c){c=getchar_unlocked();}
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
int mt,pr,lr, bc[4];
int cash = 0, know = 0; 
int dp[1001][21][5];
void dfs(int t, int k, int b){
    if (t+2<=mt) dp[t+2][k][b]=max(10+min(k,20)*pr+dp[t][k][b],dp[t+2][k][b]);
    if (k<20 && dp[t][k][b]>=20 && t+(int)(8/max(1,b*lr))<=mt) dp[t+max(1,(int)(8/max(1,b*lr)))][k+1][b]=dp[t][k][b]-20;
    if (b<4 && t+b<=20) dp[t+b][k][b+1]=max(dp[t][k][b]-bc[b],dp[t][k][b+1]);
}
int main(){
	setIO();rv(mt,pr,lr);
    for (int i=0;i<4;i++) rv(bc[i]);
    for (int i=0;i<=mt;i++){
        for (int j=0;j<4;j++){
            for (int k=0;k<4;k++){
                dp[i][j][k]=-1;
            }
        }
    }
    dfs(0,0,0);
    int mv = 0;
    for (int i=0;i<=mt;i++){
        for (int j=0;j<=20;j++){
            for (int k=0;k<=4;k++){
                mv=max(mv,dp[i][j][k]);
            }
        }
    }
    cout << mv << "\n";
}
