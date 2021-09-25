//https://cses.fi/problemset/task/1093/
// Two Sets 2 Solution
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
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
ll mod=2e9+14;
ll N;
ll dp[501*125+1];
int main(){
	memset(dp,0,sizeof(dp));
	setIO(); cin >> N;
	dp[0]=1;
	if (N%4==2 || N%4==1){cout << "0\n";return 0;}
	for (int i=1;i<=N;i++){
		for (int j=((N*(N+1))/4);j>=i;j--){
			dp[j]+=dp[j-i];
			dp[j]%=mod;
		}
	}
	cout << (((dp[(N*(N+1))/4])+mod)/2)%mod << "\n";
}
