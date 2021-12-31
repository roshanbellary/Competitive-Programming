
/*
Problem: Counting Numbers
Problem Link: https://cses.fi/problemset/task/2220/
Notes: Hard dp problem involving digits dp
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
#define mod 1e9+7
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
ll dp[10][18];
ll a,b;
ll power(ll x, ll y){
    ll res=1;
    while(y>0){
        if (y&1) res= (res*x); y=y>>1; x=(x*x);
    }
    return res;
}
ll solve(ll x) {
	if (x < 0) return 0;
	if (x == 0) return 1;
	ll f = 1;
	while(f) {
		f = 0;
		for (ll i = log10(x) - 1; i >= 0; i--) {
			ll m = power(10, i);
			if (x/(m*10)%10 == x/m%10) {
				x = (x/m - 1)*m + (m-1);
				f = 1;
			}
		}
	}
	ll N = log10(x)+1,dp[N+1][2],ans = 1,m=1;
	for (int i=0;i<=N;i++) dp[i][0]=dp[i][1]=0;
	dp[0][0] = 1, dp[0][1] = 1;
	for (ll i=1;i<N;i++,m*=10) {
		dp[i][0]=power(9, i);
		dp[i][1]=(x/m%10)*dp[i-1][0]+dp[i-1][1];
		if (x/m%10>x/(m*10)%10)dp[i][1]-=dp[i-1][0];
		ans+=dp[i][0];
	}
	dp[N][1]=(x/m%10-1)*dp[N-1][0]+dp[N-1][1];
   	return ans+dp[N][1];
}
int main(){
	setIO();
	cin >> a >> b;
	cout << solve(b)-solve(a-1) << "\n";
}
