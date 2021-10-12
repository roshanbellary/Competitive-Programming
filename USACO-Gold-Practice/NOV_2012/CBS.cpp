/*
USACO 2012 November Contest, Gold Problem 2. Concurrently Balanced Strings
http://usaco.org/index.php?page=viewproblem2&cpid=194
Had to use editorial to solve problem as I didn't understand how I could solve it in less 
than O(n^2)
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
int main(){
	setIO();
	int N,K; cin >> N >>K;
	vector<string>w(N);
	for(int i=0;i<N;i++) cin >>w[i];
	int res = 0;
	vector<int> L(N,K);
	vector<vector<int>> dp(N, vector<int>(2*K,K));
	map<vector<int>,pair<int,int>> mp;
	for(int i = 0; i < N; i++) dp[i][K] = 0;
	mp[L] = make_pair(0, 1);
	for(int i = 0; i < K; i++) {
		int lft = 0;
		for(int j = 0; j < N; j++) {
		if(w[j][i] == '(') {
			dp[j][++L[j]] = i + 1;
		} else {
			--L[j];
			dp[j][L[j]] = min(dp[j][L[j]], i + 1);
		}
		lft = max(lft, dp[j][L[j]]);
		}
		if(lft == K) continue;
		pair<int, int>& add = mp[L];
		if(add.first == lft) {
		res += add.second++;
		} else {
		add = make_pair(lft, 1);
		}
	}
	cout << res << endl;
}
