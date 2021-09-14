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
	pair<ll,ll> obj[N];
	for (int i=0;i<N;i++){
		cin >> obj[i].first >> obj[i].second;// first is weight second is value
	}
	ll dp[(int)(1e5+1)];
	for (int i=0;i<=1e5;i++) dp[i]=-1e9;
	dp[0]=0;
	for (int j=0;j<N;j++){
		for (int i=1e5;i>=0;i--){
			if (i-obj[j].second>=0){
				if ((dp[i-obj[j].second]>=0)&&(dp[i-obj[j].second]+obj[j].first<=W)){
					if (dp[i]>=0) dp[i]=min(dp[i-obj[j].second]+obj[j].first,dp[i]);
					else dp[i]=dp[i-obj[j].second]+obj[j].first;
				}
			}
		}
	}
	int pos = -1;
	for (int i=1e5;i>=0;i--){
		if (dp[i]>=0){
			pos=i;break;
		}
	}
	cout << pos << "\n";
}
