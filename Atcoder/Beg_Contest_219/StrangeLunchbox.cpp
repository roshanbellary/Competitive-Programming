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
int X,Y;
pair<int,int> l[300];
int dp[301][301];
int main(){
	setIO();
	cin >> N >> X >> Y;
	for (int i=0;i<=300;i++){
		for (int j=0;j<=300;j++){
			dp[i][j]=1e9;
		}
	}
	dp[0][0]=0;
	for (int i=0;i<N;i++){
		cin >> l[i].first >> l[i].second;
	}
	for (int p=0;p<N;p++){
		for (int i=X;i>=0;i--){
			for (int j=Y;j>=0;j--){
				dp[min(i+l[p].first,X)][min(Y,j+l[p].second)]=min(dp[i][j]+1,dp[min(i+l[p].first,X)][min(Y,j+l[p].second)]);
			}
		}
	}
	cout << ((dp[X][Y]==1e9)?-1:dp[X][Y]) << "\n";
}
