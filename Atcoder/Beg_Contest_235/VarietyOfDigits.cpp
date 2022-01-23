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
ll mod=998244353;
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
inline void rv(char &c){c=' ';while (c==' '|| c=='\n' || c==EOF) c=getchar();}
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
const int MN = 1e4+1;
string N;
ll M, v[10], bit=0, dp[MN][1<<10][2];
bool at[MN][1<<10][2];
ll modpower(int p){
    if (p==0) return 1;
    else if (p%2==1){
        ll res = modpower(p/2);
        return (((res*res)%mod)*10)%mod;
    }else{
        ll res = modpower(p/2);
        return (res*res)%mod;
    }
}
int main(){
	setIO();rv(N,M);
    for (int i=0;i<M;i++) rv(v[i]);
    for (int i=0;i<M;i++) bit|=(1<<v[i]);
    for (int i=0;i<10;i++){
        if (i==(N[0]-'0')){
            dp[0][1<<i][1]=(i*modpower(N.length()-1))%mod;
            at[0][1<<i][1]=1;
            break;
        }
        if (i) dp[0][1<<i][0]=(i*modpower(N.length()-1))%mod, at[0][1<<i][0]=1;
        else dp[0][0][0]=0, at[0][0][0]=1;
    }
    dp[0][0][0]=0;at[0][0][0]=1;
    for (int i=1;i<N.length();i++){
        for (int j=0;j<(1<<10);j++){
            for (int k=0;k<10;k++){
                if (k==0 && j==0){dp[i][0][0]=0; at[i][0][0]=1;continue;}
                if (at[i-1][j][0]) (dp[i][(j|(1<<k))][0]+=((dp[i-1][j][0])+(k*modpower(N.length()-i-1))%mod)%mod)%=mod, at[i][(j|(1<<k))][0]=1;
                if (k<(N[i]-'0') && at[i-1][j][1]) (dp[i][(j|(1<<k))][0]+=(dp[i-1][j][1]+(k*modpower(N.length()-i-1))%mod)%mod)%=mod, at[i][(j|(1<<k))][0]=1;
                if (k==(N[i]-'0') && at[i-1][j][1]) (dp[i][(j|(1<<k))][1]+=(dp[i-1][j][1]+(k*modpower(N.length()-i-1))%mod))%=mod, at[i][(j|(1<<k))][1]=1;
            }
        }
    }
    ll res = 0;
    for (int i=1;i<(1<<10);i++){
        bool w = 1;
        for (int k=0;k<M;k++) if ((i&(1<<v[k]))==0){w=0;break;}
        ll v = (dp[N.length()-1][i][0]+dp[N.length()-1][i][1])%mod;
        if (w && v){
            cout << i << " " << v << "\n";
        }
        if (w) (res+=v)%=mod;
    }
    cout << res << "\n";
}
