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
int N, K;
int main(){
	setIO();
	cin >> N >> K;
	int h[N];int dp[N];
	for (int i=0;i<N;i++){cin >> h[i];dp[i]=1e9;}
	dp[0]=0;
	for (int i=1;i<N;i++){
		for (int j=i-1;j>=max(0,i-K);j--){
			dp[i]=min(dp[j]+abs(h[j]-h[i]),dp[i]);
		}
	}
	cout << dp[N-1] << "\n";
}
