/*
Problem: Swapity Swapity Swap
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=1014
Notes: 
I solved this problem using binary lifting which is a dp technique that finds the state after 2^N steps,
but another way to solve is to directly find the resulting cycles that come from these reversals (You can simulate the movement another N times)
then find how the nodes will be after K%(length of cycle)
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
const int MN = 1e5;
int N, M, K, c[MN], r[MN],fi[MN];
int dp[MN][31];
void reversal(int s, int f){
    for (int i=s;i<(s+f+1)/2;i++){
        swap(c[f-(i-s)],c[i]);
    }
}
int main(){
	setIO("swap");rv(N, M, K);
    for (int i=0;i<N;i++) c[i]=i;
    for (int i=0;i<M;i++){
        int L, R;rv(L, R);
        reversal(--L,--R);
    }
    for (int i=0;i<N;i++) r[c[i]]=i;
    for (int i=0;i<N;i++) dp[i][0]=r[i];
    for (int k=1;k<=30;k++){
        for (int i=0;i<N;i++){
            dp[i][k]=dp[dp[i][k-1]][k-1];
        }
    }
    for (int i=0;i<N;i++){
        int ind = i;
        for (int j=30;j>=0;j--){
            if (K&(1<<j)){
                ind=dp[ind][j];
            }
        }
        fi[ind]=i;
    }
    for (int i=0;i<N;i++){
        cout << fi[i]+1 << "\n";
    }
}
