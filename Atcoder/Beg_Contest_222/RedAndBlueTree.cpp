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
int mod=998244353;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N, M, K;
int a[100];
int c[1000];
vector<pair<int,int>> l[1000];
bool dfs(int i, int p, int goal){
	if (i==goal) return true;
	for (auto j:l[i]){
		if (j.first!=p){
			if (dfs(j.first,i,goal)){
				c[j.second]++;
				return true;
			}
		}
	}
	return false;
}
int main(){
	setIO(); cin >> N >> M >> K;
	for (int i=0;i<M;i++){cin >> a[i];a[i]--;}
	for (int i=0;i<N-1;i++){
		int u,v; cin >> u >> v;
		l[--u].pb({--v,i});
		l[v].pb({u,i});
	}
	for (int i=0;i<M-1;i++){
		dfs(a[i],a[i],a[i+1]);
	}
	int sum = 0;
	for (int i=0;i<N-1;i++){
		sum+=c[i];
	}
	if ((sum+K)%2==1 || sum+K<0){
		cout << 0 << "\n";
		return 0;
	}
	int dp[(int)1e5+1];
	dp[0]=1;
	for (int j=0;j<N-1;j++){
		for (int i=1e5;i>=c[j];i--){
			dp[i]+=(dp[i-c[j]]);dp[i]%=mod;
		}
	}
	cout << dp[(sum+K)/2] << "\n";
}
