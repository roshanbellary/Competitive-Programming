#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("bbreeds.in","r",stdin);
	freopen("bbreeds.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s; cin >> s; int N = s.length();
	int dp[N][N+1][N+1];
	memset(dp,0,sizeof(dp));
	int c[2][N]; memset(c,0,sizeof(c));
	for (int i=0;i<N;i++){
		if (i==0){
			if (s[i]=='(') c[0][0]++;
			else c[1][0]++;
		}else{
			if (s[i]=='(') c[0][i]+=(c[0][i-1]+1), c[1][i]=c[1][i-1];
			else c[1][i]+=(c[1][i-1]+1),c[0][i]=c[0][i-1];
		}
	}
	if (s[0]=='('){
		dp[0][1][0]=1;
		dp[0][0][0]=1;
	}
	for (int i=1;i<N;i++){// iterate over position
		for (int j=0;j<=c[0][i];j++){//iterates over all possible # of forward ( that are associated with Holstein's
			for (int k=0;k<=c[1][i];k++){//iterates over all possible # of backward ( that are associated with Holstein's
				if (k>j) continue;
				if (c[0][i]-j<c[1][i]-k) continue;
				if (s[i]=='('){
					if (j>0) dp[i][j][k]+=dp[i-1][j-1][k];
					dp[i][j][k]+=dp[i-1][j][k];
				}else{
					if (k>0) dp[i][j][k]+=dp[i-1][j][k-1];
					dp[i][j][k]+=dp[i-1][j][k];
				}
				dp[i][j][k]%=2012;
			}
		}
	}
	int counts = 0;
	for (int i=0;i<=c[0][N-1];i++){
		for (int j=0;j<=c[1][N-1];j++){
			if (i!=j) continue;
			if (c[0][N-1]-i!=c[1][N-1]-j) continue;
			counts+=dp[N-1][i][j];
			counts%=2012;
		}
	}
	cout << counts%2012 << "\n";
}
