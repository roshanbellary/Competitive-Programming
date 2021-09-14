#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
	freopen("visitfj.in","r",stdin);
	freopen("visitfj.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int N, T; cin >> N >> T;
	vector<vector<int>> g(N,vector<int>(N,0));
	vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(3,-1)));
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			int v; cin >> v;
			g[i][j]=v;
		}
	}
	priority_queue<tuple<int,int,int,int>> pq;
	pq.push(make_tuple(0,0,0,0));
	while (!pq.empty()){
		int i = get<2>(pq.top());
		int j = get<3>(pq.top());
		int l = get<1>(pq.top());
		int t = -get<0>(pq.top());
		pq.pop();
		if ((dp[i][j][l%3]<0)||(dp[i][j][l%3]>t)){
			dp[i][j][l%3]=t;
			t+=T;
			if (i>0){
				int a = t;
				if (((l+1)%3==0)) a+=g[i-1][j];
				if ((dp[i-1][j][(l+1)%3])<0||(dp[i-1][j][(l+1)%3]>a)) pq.push(make_tuple(-a,l+1,i-1,j));
			}
			if (j>0){
				int a = t;
				if ((l+1)%3==0) a+=g[i][j-1];
				if ((dp[i][j-1][(l+1)%3])<0||(dp[i][j-1][(l+1)%3]>a)) pq.push(make_tuple(-a,l+1,i,j-1));
			}
			if (i<N-1){
				int a = t;
				if ((l+1)%3==0) a+=g[i+1][j];
				if ((dp[i+1][j][(l+1)%3]<0)||(dp[i+1][j][(l+1)%3]>a)) pq.push(make_tuple(-a,l+1,i+1,j));
			}
			if (j<N-1){
				int a = t;
				if ((l+1)%3==0) a+=g[i][j+1];
				if ((dp[i][j+1][(l+1)%3])<0||(dp[i][j+1][(l+1)%3]>a)) pq.push(make_tuple(-a,l+1,i,j+1));
			}
		}
	}
	int totmin = 1e8;
	for (int i=0;i<3;i++){
		totmin = min(totmin,dp[N-1][N-1][i]);
	}
	cout << totmin << "\n";
}
