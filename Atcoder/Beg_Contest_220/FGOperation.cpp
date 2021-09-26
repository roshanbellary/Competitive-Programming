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
ll mod=998244353;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N;
ll a[(int)1e5];
ll dp[(int)1e5][10];
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++) cin >> a[i];
	for (int i=0;i<N;i++){
		for (int j=0;j<10;j++){
			dp[i][j]=0;
		}
	}
	dp[0][a[0]]=1;
	for (int i=1;i<N;i++){
		for (int j=0;j<10;j++){
			int n = (j+a[i])%10;
			int p = (j*a[i])%10;
			dp[i][n]+=(dp[i-1][j]%mod); dp[i][n]%=mod;
			dp[i][p]+=(dp[i-1][j]%mod); dp[i][p]%=mod;
		}
	}
	for (int i=0;i<10;i++){
		cout << dp[N-1][i] << "\n";
	}
}
