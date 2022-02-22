/*
██████╗░░█████╗░██████╗░███████╗██╗░░░░░██╗░░░░░
██╔══██╗██╔══██╗██╔══██╗██╔════╝██║░░░░░██║░░░░░
██████╔╝██║░░██║██████╦╝█████╗░░██║░░░░░██║░░░░░
██╔══██╗██║░░██║██╔══██╗██╔══╝░░██║░░░░░██║░░░░░
██║░░██║╚█████╔╝██████╦╝███████╗███████╗███████╗
╚═╝░░╚═╝░╚════╝░╚═════╝░╚══════╝╚══════╝╚══════╝
Problem: Make Them Equal
Problem Link: https://codeforces.com/problemset/problem/1633/D
Notes: Reduce K to 12*N as the maximum value for a distance from 1 -> 10^3 is 12
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
const int MV = 1e3+1, MN = 1e3, MM = 1e6+1;
ll T, d[MV], N, K, b[MN], c[MN], dp[MM];
queue<int> q;
void solve(){
    rv(N, K);
    for (int i=0;i<N;i++) rv(b[i]);
    for (int i=0;i<N;i++) rv(c[i]);
    fill(dp,dp+MM,0);
    for (int i=0;i<N;i++) b[i]=d[b[i]];
    dp[0]=0;
    for (int i=0;i<N;i++){
        for (int j=min(K,12*N)-b[i];j>=0;j--){
            dp[j+b[i]]=max(dp[j]+c[i],dp[j+b[i]]);
        }
    }
    ll MV = 0;
    for (int i=0;i<=K;i++) MV=max(MV,dp[i]);
    cout << MV << "\n";
}
void factors(vector<int> &ft, int n){
    set<int> s;
    for (int i=1;i<=n;i++) s.insert(n/i);
    for (int j:s) ft.eb(j);
}
int main(){
	setIO();rv(T);
    d[1]=0;q.push(1);
    vector<int> ft;
    while (!q.empty()){
        int ind = q.front();q.pop();
        ft.clear();factors(ft,ind);
        for (auto& a:ft){
            if (ind+a>=MV) continue;
            else if (d[ind+a]==0){
                d[ind+a]=d[ind]+1;q.push(ind+a);
            }
        }
    }
    while (T--) solve();
}
