/*
Problem: Slimes
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_n
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
const int MN = 400;
int N;
ll v[MN],dp[MN][MN],p[MN];
ll sum(int i, int j){
    if (i) return p[j]-p[i-1];
    else return p[j];
}
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++) rv(v[i]);
    for (int i=0;i<N-1;i++) dp[i][0]=v[i];
    for (int i=0;i<N;i++){
        p[i]=v[i];if (i) (p[i]+=p[i-1]);
    }
    for (int i=1;i<N;i++){
        for (int j=0;j<N;j++){
            if (j+i>=N) break;
            dp[j][i]=sum(j,j+i);
            ll v = 1e18;
            for (int k=0;k<i;k++){
                ll col=0;
                if (k>0) (col+=dp[j][k]);
                if (i-k-1>0) (col+=dp[j+k+1][i-k-1]);
                v=min(col,v);
            }
            (dp[j][i]+=v);
        }
    }
    cout << dp[0][N-1] << "\n";
}
