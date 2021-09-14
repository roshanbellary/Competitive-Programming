#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N, W;
int main(){
	setIO();
	cin >> N >> W;
	pair<ll,ll> o[N];
	for (int i=0;i<N;i++){
		cin >> o[i].first >> o[i].second;
	}
	sort(o,o+N);
	ll dp[W+1][N];
	for (int i=0;i<=W;i++){
		for (int j=0;j<N;j++){
			dp[i][j]=-1e9;
		}
	}
	for (int j=0;j<N;j++){
		dp[0][j]=0;
	}
	for (int i=1;i<=W;i++){
		for (int j=0;j<N;j++){
			if ((j==0)&&(i-o[j].first==0)){
				dp[i][0]=o[j].second;
			}else if ((i-o[j].first>=0)&&(j!=0)){
				if (dp[i-o[j].first][j-1]>=0) dp[i][j]=dp[i-o[j].first][j-1]+o[j].second;
			}
			if (j!=0) dp[i][j]=max(dp[i][j-1],dp[i][j]);
		}
	}
	ll totmax = 0;
	for (int i=0;i<=W;i++){
		totmax=max(dp[i][N-1],totmax);
	}
	cout << totmax << "\n";
}
