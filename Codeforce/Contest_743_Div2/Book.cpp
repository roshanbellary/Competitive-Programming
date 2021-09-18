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
#define mod 1e9+7
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int T,N;
vector<vector<int>> a;
vector<int> v;
vector<int> dp;
bool cycle = false;
void dfs(int i, int t){
	v[i]=t;
	for (int j:a[i]){
		if (v[j]==t){
			cycle = true;
			return;
		}
	}
	for (int j:a[i]){
		if (v[j]==0) dfs(j,t);
	}
}
bool checkCycle(){
	int c = 1;
	for (int i=0;i<N;i++){
		if (v[i]==0){
			dfs(i,c);c++;
		}
	}
	return cycle;
}
void dfs2(int i){
	if (a[i].size()==0){
		dp[i]=1;
	}else{
		int maxi = 0;
		for (int j:a[i]){
			if (dp[j]==0) dfs2(j);
			if (j<=i) maxi=max(dp[j],maxi);
			else maxi=max(dp[j]+1,maxi);
		}
		dp[i]=maxi;
	}
}
int setDp(){
	int maxi = 0;
	for (int i=0;i<N;i++){
		if (dp[i]==0){
			dfs2(i);
			maxi=max(maxi,dp[i]);
		}
	}
	return maxi;
}
int main(){
	setIO();
	cin >> T;
	for (int l=0;l<T;l++){
		cin >> N;
		for (int i=0;i<N;i++) a.pb(vector<int>()),v.pb(0), dp.pb(0);
		for (int i=0;i<N;i++){
			int k; cin >> k;
			for (int j=0;j<k;j++){
				int b; cin >> b; b--;
				a[i].pb(b);
			}
		}
		if (checkCycle()){
			cout << "-1\n";
		}else{
			cout << setDp() << "\n";
		}
		cycle=false;
		a.clear();v.clear();dp.clear();
	}
}
