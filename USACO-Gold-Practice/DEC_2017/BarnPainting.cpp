#include <bits/stdc++.h>
#define int long long
int mod = 1e9+7;
using namespace std;
vector<vector<int>> l;
vector<vector<int>> dp;
void dfs(int i, int parent){
	for (int j:l[i]){
		if (j!=parent){
			dfs(j,i);
			for (int c=0;c<3;c++){
				dp[i][c]*=((dp[j][(c+1)%3]+dp[j][(c+2)%3])%mod);
				dp[i][c]%=mod;
			}
		}
	}
}
int32_t main(){
	freopen("barnpainting.in","r",stdin);
	freopen("barnpainting.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int N, K; cin >> N >> K;
	for (int i=0;i<N;i++) l.push_back(vector<int>());
	for (int i=0;i<N-1;i++){
		int x,y; cin >> x >> y;
		x--;y--;
		l[x].push_back(y);
		l[y].push_back(x);
	}
	for (int i=0;i<N;i++){
		dp.push_back(vector<long long>(3,1));
	}
	for (int i=0;i<K;i++){
		int b, c; cin >> b >> c; b--; c--;
		dp[b][c]=1; dp[b][(c+1)%3]=0;dp[b][(c+2)%3]=0;
	}
	dfs(0,0);
	int maxi = 0;
	for (int c=0;c<3;c++){
		maxi+=(dp[0][c]%mod);
		maxi%=(mod);
	}
	cout << maxi << "\n";
}
