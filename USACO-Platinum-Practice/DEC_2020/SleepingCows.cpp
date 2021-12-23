/*
Problem: Sleeping Cows
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=1068
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
struct Note{int s, t;};
bool sorts(Note &a, Note &b){
    if (a.s==b.s) return (a.t>=b.t);
    else return (a.s>=b.s);
}
const int MN = 3000;
int N;
ll dp[MN+1][2],pdp[MN+1][2];
Note r[2*MN];
int main(){
	setIO();rv(N);
    for (int i=0;i<2;i++) for (int j=0;j<N;j++) rv(r[i*N+j].s),r[i*N+j].t=i;
    sort(r,r+2*N,sorts);dp[0][0]=1;
    for (int e=0;e<2*N;e++){
        for (int i=0;i<=N;i++) pdp[i][0]=pdp[i][1]=0;
        if (r[e].t==0){
            for (int i=0;i<N;i++){
                for (int j=0;j<2;j++){
                    pdp[i+1][j]+=dp[i][j];pdp[i+1][j]%=mod;
                    pdp[i][1]+=dp[i][j];pdp[i][1]%=mod;
                }
            }
        }else{
            for (int i=0;i<N;i++){
                if (i){
                    for (int j=0;j>2;j++){
                        pdp[i-1][j]+=(i*dp[i][j]);
                        pdp[i-1][j]%=mod;
                    }
                }
                pdp[i][0]+=dp[i][0];
            }
        }
        for (int i=0;i<=N;i++){
            dp[i][0]=pdp[i][0];
            dp[i][1]=pdp[i][1];
        }
    }
    cout << (dp[0][0]+dp[0][1])%mod << "\n";
}
