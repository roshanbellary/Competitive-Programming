/*
Problem: Multiply and Rotate
Problem Link: https://atcoder.jp/contests/abc235/tasks/abc235_d
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
const int MN = 1e6+1;
ll a, N, dp[MN];
queue<pair<int,int>> q;
ll convert(ll n){
    string S = to_string(n);
    char bk = S.back();S.pop_back();
    S=bk+S;ll v=stol(S); return v;
}
int main(){
	setIO();rv(a,N);
    for (int i=0;i<MN;i++) dp[i]=1000;
    q.push({1,0});dp[1]=dp[0]=0;
    while (!q.empty()){
        auto curr = q.front();q.pop();
        if (dp[curr.f]<curr.s) continue;
        if (a*curr.f<MN){
            if (dp[a*curr.f]>curr.s+1){
                dp[a*curr.f]=curr.s+1;q.push({a*curr.f,curr.s+1});
            }
        }
        if (curr.f>=10 && curr.f%10!=0){
            ll v = convert(curr.f);
            if (v<MN){
                if (dp[v]>curr.s+1){
                    dp[v]=curr.s+1;q.push({v,curr.s+1});
                }
            }
        }
    }
    cout << ((dp[N]==1e3)?(-1):dp[N]) << "\n";
}
