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
int mod=998244353;
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
int a[(int)3e3],b[(int)3e3];
int dp[3001][3001];
int main(){
	setIO(); cin >> N;
	for (int i=0;i<N;i++) cin >> a[i];
	for (int i=0;i<N;i++) cin >> b[i];
	dp[0][0]=1;
	for (int i=0;i<=N;i++){
		for (int j=0;j<3000;j++){
			dp[i][j+1]+=(dp[i][j]%mod);
			dp[i][j+1]%=mod;
		}
		if (i!=N){for (int j=a[i];j<=b[i];j++){dp[i+1][j]+=(dp[i][j]%mod);dp[i+1][j]%=mod;}}
	}
	cout << dp[N][3000] << "\n";
}
