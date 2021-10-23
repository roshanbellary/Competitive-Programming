/*
IOI 2005 F. Rivers
https://contest.yandex.com/ioi/contest/566/problems/F/
This was a pretty hard dp on trees problem that took me a while to understand and solve. I did 
finally get how to do the transitions
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
int n,k,w[101],v[101],d[101];
vector<ll> dp[101][101];
vector<pair<int,int>> child[101];
vector<ll> combine(vector<ll> a, vector<ll> b) {
	vector<ll> c(a.size()+b.size()-1,2e9);
	for (int i=0;i<a.size();i++){
		for (int j=0;j<b.size();j++){
			c[i+j]=min(c[i+j],a[i]+b[j]);
		}
	}
	return c;
}
vector<ll> add(vector<ll> a, vector<ll> b) {
	b.insert(begin(b),2e9);
	while (a.size() < b.size()) a.pb(2e9);
	for (int i=0;i<b.size();i++){
		a[i]=min(a[i],b[i]);
	}
	return a;
}
vector<ll> dfs(int a, int p, int d) {
	if ((dp[a][p].size())) return dp[a][p];
	dp[a][p] = {d*w[a]};
	for (pair<int,int> t:child[a]){
		vector<ll> v = dfs(t.first,p,d+t.second);
		dp[a][p]=combine(dp[a][p],v);
	}
	if (p!=a) dp[a][p]=add(dp[a][p],dfs(a,a,0));
	return dp[a][p];
}
int main(){
	setIO();
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> w[i] >> v[i] >> d[i];
		child[v[i]].pb({i,d[i]});
	}
	vector<ll> res = dfs(0,0,0);
	cout << res[k] << "\n";
}
