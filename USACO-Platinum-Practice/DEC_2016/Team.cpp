/*
USACO 2016 December Contest, Platinum Problem 2. Team Building
http://www.usaco.org/index.php?page=viewproblem2&cpid=673
DP transitions were hard to figure out until I realized that I can use prefix sums.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ll long long
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
int mod = 1e9+7;
int N, M, K;
ll a[1001];
ll b[1001];
int main(){
	setIO("team");
	cin >> N >> M >> K;
	for (int i=0;i<N;i++){cin >> a[i];}
	for (int i=0;i<M;i++){cin >> b[i];}
	sort(a,a+N);
	sort(b,b+M);
	vector<vector<ll>> dp(N+1,vector<ll>(M+1,1));
	for (int k=K;k>0;k--){
		vector<vector<ll>> n(N+1, vector<ll>(M+1,0));
		for (int i=0;i<N;i++){
			for (int j=0;j<M;j++){
				if (a[i]<=b[j]) continue;
				n[i+1][j+1]+=(dp[i][j]%mod);
				n[i+1][j+1]%=mod;
			}
		}
		dp=n;
		for (int i=0;i<N+1;i++){
			for (int j=0;j<M+1;j++){
				if (i>0) dp[i][j]+=dp[i-1][j];
				if (j>0) dp[i][j]+=dp[i][j-1];
				if ((i>0)&&(j>0)) dp[i][j]-=dp[i-1][j-1];
				dp[i][j]%=mod;
				dp[i][j]+=mod;
				dp[i][j]%=mod;
			}
		}
	}
	cout << dp[N][M]%mod << "\n";
}
