#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int N, K; cin >> N >> K;
	vector<int> a(N);
	for (int i=0;i<N;i++){
		cin >> a[i];
	}
	int dp[N][K+1]; //i-last group contained, j-changes of net, k-#of collected groups
	memset(dp,1e9,sizeof(dp));
	dp[0][0]=0;
	int maxa[N]; maxa[0]=a[0];
	for (int i=1;i<N;i++){
		maxa[i]=max(maxa[i-1],a[i]);
	}
	int p[N];
	for (int i=0;i<N;i++){
		if (i==0) p[i]=a[i];
		else p[i]=p[i-1]+a[i];
	}
	for (int i=1;i<N;i++){
		for (int j=0;j<=K;j++){
			if (j>0){
				int maxi = a[i]; int sum = a[i]; int totmin = 1e9;
				for (int z=i-1;z>=0;z--){
					totmin=min(totmin,dp[z][j-1]+maxi*(i-z)-sum);
					sum+=a[z]; maxi=max(maxi,a[z]);
				}
				dp[i][j]=min(totmin,dp[i-1][0]);
			}else{
				dp[i][0]=maxa[i]*(i+1)-p[i];
			}
		}
	}
	int totmin = 1e9;
	for (int i=0;i<=K;i++){
		totmin=min(totmin,dp[N-1][i]);
	}
	cout << totmin << "\n";
}
