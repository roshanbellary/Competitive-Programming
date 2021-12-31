/*
Problem: Counting Tilings
Problem Link: https://cses.fi/problemset/task/2181/
Notes: Super hard dp problem. Best thing to do is look at how you can transition between two columns via
a bitmask and whether the dimensionality of that bitmask can be lowered
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
int N, M;
ll dp[1<<10][1000];
bool r[1<<10][1<<10];
int main(){
	setIO();rv(N, M);
    for (int i=0;i<(1<<N);i++){
        for (int j=0;j<(1<<N);j++){
            bool w = 1;
            for (int k=0;k<N;k++){
                int b1 = (i&(1<<k)), b2 = (j&(1<<k));
                if (b1==0 && b2==0) w=0;
            }
            int k;
            for (k=0;k<N-1;k++){
                int b1 = (i&(1<<k)), b2 = (j&(1<<k));
                if (b1!=0 && b2!=0){
                    int b3 = (i&(1<<(k+1))), b4 = (j&(1<<(k+1)));
                    if (b3!=0 && b4!=0) k++;
                    else{w=0;break;} 
                }
            }
            if (k==N-1){
                int b1 = (i&(1<<k)), b2 = (j&(1<<k));
                if (b1!=0 && b2!=0) w=0;
            }
            r[i][j]=w;
        }
    }
    for (int i=0;i<(1<<N);i++){
        bool w = 1; int j;
        for (j=0;j<N-1;j++){
            if ((i&(1<<j))!=0){
                if ((i&(1<<(j+1)))==0){w=0;break;}
                else j++;
            }
        }
        if (j==N-1) if ((i&(1<<j))!=0) w=0;
        dp[i][0]=w;
    }
    for (int i=1;i<M-1;i++){
        for (int j=0;j<(1<<N);j++){
            for (int k=0;k<(1<<N);k++){
                (dp[j][i]+=(dp[k][i-1]*r[k][j]))%=mod;
            }
        }
    }
    for (int k=0;k<(1<<N);k++) (dp[(1<<N)-1][M-1]+=(dp[k][M-2]*r[k][(1<<N)-1]))%=mod;
    cout << dp[(1<<N)-1][M-1] << "\n";
}
