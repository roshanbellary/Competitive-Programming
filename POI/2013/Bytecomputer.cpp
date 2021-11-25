/*
Problem: Polish Olympiad 2013 Task: Byte Computer
Link: https://szkopul.edu.pl/problemset/problem/i3cF1qQtiXwmwOc_5qRB0ufC/site/?key=statement
Notes: Dp solution where we just store the minimum number of operations to get to a point
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
int N, dp[(int)1e6][3],v[(int)1e6];
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++){rv(v[i]);v[i]++;}
    for (int i=0;i<N;i++) dp[i][0]=dp[i][1]=dp[i][2]=1e9;
    dp[0][v[0]]=0;dp[0][(v[0]+1)%3]=dp[0][(v[0]+2)%3]=1e9;
    for (int i=1;i<N;i++){
        if (v[i]==2){
            int minv = 1e9;
            for (int j=0;j<3;j++){
                minv=min(minv,dp[i-1][j]);
            }
            dp[i][v[i]]=minv;
            if (dp[i-1][0]!=1e9){
                dp[i][1]=dp[i-1][0]+1;
                dp[i][0]=dp[i-1][0]+2;
            }
        }else if (v[i]==1){
            int minv = 1e9;
            for (int j=0;j<2;j++){
                minv=min(minv,dp[i-1][j]);
            }
            dp[i][v[i]]=minv;
            if (dp[i-1][0]!=1e9){
                dp[i][0]=dp[i-1][0]+1;
            }
            if (dp[i-1][2]!=1e9){
                dp[i][1]=dp[i-1][2]+1;
            }
        }else{
            dp[i][0]=dp[i-1][0];
            if (dp[i-1][2]!=1e9){
                dp[i][1]=dp[i-1][2]+1;
                dp[i][2]=dp[i-1][2]+2;
            }
        }
    }
    int minv = 1e9;
    for (int i=0;i<3;i++) minv=min(minv,dp[N-1][i]);
    cout << ((minv==1e9)?"BRAK":to_string(minv))<< "\n";
}
