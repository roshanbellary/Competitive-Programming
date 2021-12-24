/*
Problem: PairedUp
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=1161
Notes: Hard prob
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
int t, n, k;
int mincost(vector<pair<int, int>>& v, int k) {
    int mn =1e9;
    for (int i = 0; i < v.size(); i++) if (!(i & 1) || v[i + 1].first - v[i - 1].first <= k) mn = min(mn, v[i].second);
    return mn;
}
int maxcost(vector<pair<int, int>>& v, int k) {
    int n = v.size();
    if (!n) return 0;
    vector<pair<int, int>> dp(n + 1);
    dp[n] = {0, -1e9};
    for (int i = n - 1; ~i; i--) {
        dp[i] = dp[i + 1];
        int ub = upper_bound(v.begin(), v.end(),make_pair(v[i].first + k, 1e9)) - v.begin();
        if (i == 0 || i == n - 1 || v[i + 1].first - v[i - 1].first <= k || !(n - i & 1)) dp[i].first = max(dp[i].first, dp[ub].second + v[i].second);
        if (i == 0 || i == n - 1 || v[i + 1].first - v[i - 1].first <= k || (n - i & 1)) dp[i].second = max(dp[i].second, dp[ub].first + v[i].second);
    }
    return ((n & 1) ? dp[0].second : dp[0].first);
}
int main() {
    setIO();rv(t,n,k);
    int prev_x = 0, ans = 0;
    vector<pair<int, int>> curr_v;
    while (n--) {
        int x, y; rv(x,y);
        if (x - prev_x > k) {
            if (t == 1) if (curr_v.size() & 1) ans += mincost(curr_v, k);
            else ans += maxcost(curr_v, k);
            curr_v.clear();
        }
        curr_v.pb({x, y});
        prev_x = x;
    }
    if (t == 1) if (curr_v.size() & 1) ans += mincost(curr_v, k);
    else ans += maxcost(curr_v, k);
    cout << ans << "\n";
    return 0;
}
