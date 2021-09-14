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
int N;
int main(){
	setIO();
	cin >> N;
	int h[N+1];
	int dp[N+1];
	for (int i=0;i<N;i++) cin >> h[i+1];
	dp[1]=0;
	h[0]=0;
	for (int i=2;i<=N;i++){
		if (i>2) dp[i]=min(dp[i-2]+abs(h[i]-h[i-2]),dp[i-1]+abs(h[i]-h[i-1]));
		else dp[i]=dp[i-1]+abs(h[i]-h[i-1]);
	}
	cout << dp[N] << "\n";

}
