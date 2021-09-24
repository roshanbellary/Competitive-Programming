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
int a, b;
int dp[501][501];
void checkCuts(int a, int b){
	if (a==b){
		dp[a][b]=0;
	}else{
		int mini = 1e9;
		for (int i=1;i<a;i++){
			if (dp[i][b]==1e9) checkCuts(i,b);
			if (dp[a-i][b]==1e9) checkCuts(a-i,b);
			mini=min(dp[i][b]+dp[a-i][b]+1,mini);
		}
		for (int j=1;j<b;j++){
			if (dp[a][j]==1e9) checkCuts(a,j);
			if (dp[a][b-j]==1e9) checkCuts(a,b-j);
			mini=min(dp[a][j]+dp[a][b-j]+1,mini);
		}
		dp[a][b]=mini;
	}
}
int main(){
	setIO();
	for (int i=1;i<=500;i++){
		for (int j=1;j<=500;j++) dp[i][j]=1e9;
	}
	cin >> a >> b;
	checkCuts(a,b);
	cout << dp[a][b] << "\n";
}
