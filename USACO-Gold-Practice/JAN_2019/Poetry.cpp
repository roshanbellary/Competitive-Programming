/*
Problem: Poetry
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=897
Notes: Modular Exponentiation Prob w/ Knapsack DP
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
ll mod=1e9+7;
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
const int MN = 5000, MK = 5001;
ll N, M, K, dp[MK], a[26], le[MN];
ll mult[MN][27], res=1;
vector<int> l[MN], syl;
ll modpower(ll v, int p){
    if (p==0) return 1;
    if (p%2==0){
        ll res = modpower(v,p/2);
        return (res*res)%mod;
    }else{
        ll res = modpower(v,p/2);
        (res*=res)%=mod;
        return (res*v)%mod;
    }
}
int main(){
	setIO("poetry");rv(N, M, K);dp[0]=1;
    for (int i=0;i<N;i++){
        int s, c; rv(s,c);
        l[--c].eb(s);syl.eb(s);
    }
    sort(syl.begin(),syl.end());
    for (int i=0;i<=K;i++){
        for (int& j:syl){
            if (i+j>K) break;
            (dp[i+j]+=dp[i])%=mod;
        }
    }
    for (int i=0;i<N;i++) for (int& j:l[i]) if (K>=j) (le[i]+=dp[K-j])%=mod;
    while (M--){
        string s; rv(s);
        a[s[0]-'A']++;
    }
    for (int i=0;i<26;i++){
        if (!a[i]) continue;
        ll col = 0;
        for (int j=0;j<N;j++) (col+=modpower(le[j],a[i]))%=mod;
        (res*=col)%=mod;
    }
    cout << res << "\n";
}
