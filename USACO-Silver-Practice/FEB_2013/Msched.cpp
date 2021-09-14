#include <bits/stdc++.h>
#define int long long
using namespace std;
int N, M;
vector<vector<int>> l;
vector<int> dp;
vector<bool> v;
vector<int> t;
int totmax = 0;
void dfs(int i){
	if (dp[i]>0) return;
	v[i]=true;
	dp[i]=t[i];
	for (int j:l[i]){
		dfs(j);
		dp[i]=max(dp[i],dp[j]+t[i]);
	}
	totmax=max(totmax,dp[i]);
}
int32_t main(){
	freopen("msched.in","r",stdin);
	freopen("msched.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> N >> M;
	for (int i=0;i<N;i++)
		l.push_back(vector<int>());
	dp.resize(N,0);
	v.resize(N,false);
	for (int i=0;i<N;i++){
		int s; cin >> s;
		t.push_back(s);
	}
	for (int i=0;i<M;i++){
		int a,b; cin >> a >> b;
		a--; b--;
		l[a].push_back(b);
	}
	for (int i=0;i<N;i++){
		dfs(i);
	}
	cout << totmax << "\n";
}
