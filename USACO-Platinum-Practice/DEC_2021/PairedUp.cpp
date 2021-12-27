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
const int MN = 5001;
int N, K, gl[MN], hl[MN];
ll gw[MN],hw[MN];
bool isg[MN];
int main(){
	setIO();rv(N, K);
    int g, h = 1;
    for (int i=0;i<N;i++){
        string t;int l; ll w; rv(t, l, w);
        if (t=="G"){
            isg[i]=1;gl[g]=l;gw[g]=w;g++;
        }else{
            isg[i]=0;hl[h]=l;hw[h]=w;h++;
        }
    }
    int vp[g+1][h+1];
    for (int i=g;i>=0;i--){
        for (int j=h;j>=0;j--){
            if (i<g && j<h && abs(gl[i+1]-hl[j+1])<=K){
                vp[i][j]=vp[i+1][j+1];
            }else{
                vp[i][j]=i;
            }
       }
    }
    int lh[g+1], lg[h+1];
    for (int i=1;i<=g+1;i++){
        while (lh[i]<=h && hl[lh[i]] <=gl[i]+K){
            lh[i]++;
        }
        lh[i]--;
    }
    for (int i=1;i<=h+1;i++){
        while (lg[i]<=g && gl[lg[i]] <=hl[i]+K){
            lg[i]++;
        }
        lg[i]--;
    }
    ll dp[2][g+1][h+1];
    dp[0][0][0]=dp[1][0][0]=0;
    for (int i=0;i<=g;i++){
        for (int j=0;j<=h;j++){
            int nj = max(j, lh[i]);
            if (vp[i][j]-i+j>=nj){
                dp[1][nj-j+i][nj]=max(dp[1][nj-j+i][nj], dp[0][i][j]);
            }
            int ni = max(i, lg[i]);
            if (vp[i][j]>=ni) {
                dp[0][ni][ni-i+j] = max(dp[0][ni][ni-i+j], dp[1][i][j]);
            }
            if (vp[i][j]>= i + 1) {
                dp[0][i+1][j+1] = max(dp[0][i+1][j+1], dp[0][i][j]);
                dp[1][i+1][j+1] = max(dp[1][i+1][j+1],dp[1][i][j]);
            }

        }
    }
    cout << max(dp[0][g][h],dp[1][g][h]) << "\n";
}
