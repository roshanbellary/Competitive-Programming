
/*
USACO 2016 US Open Contest, Platinum Problem 1. 262144
http://www.usaco.org/index.php?page=viewproblem2&cpid=648
Cool dp problem it was initially hard for me to think of the transitions.
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
int N;
int v[262144];
int ldp[262144];
int rdp[262144];
int dp[262145][70];
int main(){
	setIO("262144");
	cin >> N;
	for (int i=0;i<N;i++) cin>>v[i];
	ldp[0]=v[0];
	int res = 0;
	for (int i=0;i<=70;i++){
		for (int j=0;j<N;j++){
			if (v[j]==i){
				dp[j][i]=j+1;res=max(res,i);
			}else{
				if (i==0||dp[j][i-1]==-1||dp[dp[j][i-1]][i-1]==-1) dp[j][i]=-1;
				else{
					dp[j][i]=dp[dp[j][i-1]][i-1];
					res=max(res,i);
				}
			}
		}
		dp[N][i]=-1;
	}
	cout << res << "\n";
}
