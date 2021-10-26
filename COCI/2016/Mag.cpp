/* 
Problem: COCI 2016/2017 Round #1, October 15th, 2016 Task Mag 
Problem Link: https://oj.uz/problem/view/COCI16_mag
Notes: I had a lot of trouble with figuring out the dp on trees way to solve this problem, so 
I finally had to look at the editorial in order to understan the solution.
*/
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
#define f first
int mod=1e9+7;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int n, a[(int)1e6], df[(int)1e6], ds[(int)1e6], dt[(int)1e6], dp[(int)1e6];
vector<int> adj[(int)1e6];
int bfs(int s, int d[]) {
	d[s]=0;
	vector<int> q={s};
	for (int i=0; i<q.size(); ++i) {
		int u=q[i];
		for (int v : adj[u])
			if (a[v]==1&&d[v]==-1) {
				d[v]=d[u]+1;
				q.push_back(v);
			}
	}
	return q[q.size()-1];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i)
		cin >> a[i];
	if (*min_element(a, a+n)>1) {
		cout << *min_element(a, a+n) << "/1";
		return 0;
	}
	memset(df, -1, sizeof(df));
	memset(ds, -1, sizeof(ds));
	memset(dt, -1, sizeof(dt));
	for (int i=0; i<n; ++i)
		if (df[i]==-1 && a[i]==1) {
			int u=bfs(i, df);
			int v=bfs(u, ds);
			bfs(v, dt);
		}
	for (int i=0; i<n; ++i)
		if (ds[i]^-1)
			dp[i]=max(ds[i], dt[i])+1;
	pair<int,int> ans={1, *max_element(dp, dp+n)};
	for (int i=0; i<n; ++i)
		if (a[i]==2) {
			pair<int,int> b={-1, 0};
			for (int j : adj[i])
				if (a[j]==1 && dp[j]>=b.first) {
					if (dp[j]>b.first) b={dp[j], 1};
					else ++b.second;
				}
			if (b.first^-1&&b.second>=2){
				if (2*ans.second<(2*b.first+1)*ans.first) ans={2, 2*b.first+1};
			}
		}
	cout << ans.first << "/" << ans.second;
	return 0;
}
