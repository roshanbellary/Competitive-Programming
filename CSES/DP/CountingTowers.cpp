#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
typedef long long ll;
#define countbits __builtin_popcount
#define beg0 __builtin_clz
#define terminal0 __builtin_ctz
int mod = 1e9+7;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int T;
ll dp[(int)(1e6+1)][2];
int main(){
	setIO();
	cin >> T;
	int N;
	N=1e6;
	for (int i=0;i<N;i++){
		for (int j=0;j<2;j++){
			dp[i][j]=0;
		}
	}
	dp[0][0]=1; dp[0][1]=1;
	for (int i=1;i<N;i++){
		dp[i][0]=4*dp[i-1][0]+dp[i-1][1];
		dp[i][1]=(dp[i-1][0]+2*dp[i-1][1]);
		dp[i][0]%=mod;
		dp[i][1]%=mod;
	}
	for (int l=0;l<T;l++){
		cin >> N;
		cout << (dp[N-1][0]+dp[N-1][1])%mod << "\n";
	}
}
