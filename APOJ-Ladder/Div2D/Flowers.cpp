#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
}
void setIO(string f){
	string in = f+".in";
	string out = f+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	setIO();
}
int T,K;
const int s = 1e5+1;
ll dp[s];
int mod = 1e9+7;
ll modsum(ll x, ll y){
	ll r = (x%mod)+(y%mod);
	r%=mod;
	return r;
}
int main(){
	setIO();
	cin >> T >> K;
	for (int i=0;i<s;i++) dp[i]=0;
	dp[0]=1;
	for (int i=1;i<=1e5;i++){
		dp[i]=modsum(dp[i],dp[i-1]);
		if (i>=K){
			dp[i]=modsum(dp[i],dp[i-K]);
		}
	}
	ll sum[s];
	sum[0]=1;
	for (int i=1;i<s;i++){
		sum[i]=modsum(sum[i-1],dp[i]);
	}
	for (int l=0;l<T;l++){
		int a, b; cin >> a >> b;
		cout << ((sum[b]-sum[a-1])%mod+mod)%mod << "\n";
	}

}
