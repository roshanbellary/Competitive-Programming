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
int N, L;
int dp[(1<<20)];
vector<int> v[20];
int dur[20];
int main(){
	setIO("movie");
	cin >> N >> L;
	memset(dp,-1,sizeof(dp));
	for (int i=0;i<N;i++){
		int c; cin >> dur[i] >> c;
		for (int j=0;j<c;j++){
			int s; cin >> s;
			v[i].pb(s);
		}
	}
	for (int i=0;i<N;i++){
		if (v[i][0]==0){
			dp[(1<<i)]=dur[i];
		}
	}
	for (int i=0;i<(1<<N);i++){
		if (dp[i]>=0) continue;
		for (int j=0;j<N;j++){
			if (i&(1<<j)){
				int num = (i&(~(1<<j)));
				if (dp[num]>0){
					int s = 0;
					int f = v[j].size()-1;
					while (s<f){
						int mid = (s+f+1)/2;
						if (v[j][mid]<=dp[num]){
							s=mid;
						}else{
							f=mid-1;
						}
					}
					if (v[j][s]<=dp[num] && v[j][s]+dur[j]>=dp[num]){
						dp[i]=max(v[j][s]+dur[j],dp[i]);
					}
				}
			}
		}
	}
	int minN = 1e9;
	for (int i=0;i<(1<<N);i++){
		if (dp[i]>=L){
			minN=min(countbits(i),minN);
		}
	}
	cout << ((minN==1e9)?"-1":to_string(minN)) << "\n";
}
