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
int mod=1e9+7;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N,a[(int)3e5],b[(int)3e5],dp[(int)3e5+1], child[(int)3e5+1], diffs[(int)3e5+1];
int main(){
	setIO(); cin >> N;
	for (int i=0;i<=N;i++) dp[i]=1e9;
	for (int i=0;i<N;i++){cin >> a[i];}
	for (int i=0;i<N;i++) cin >> b[i];
	dp[N]=0;
	queue<pair<int,int>> q;
	q.push({N,0});
	while (!q.empty()){
		int ind = q.front().first;
		int d = q.front().second; q.pop();
		if (d>dp[ind]) continue;
		if (ind==0) break;
		d++;
		if (ind-a[ind-1]<=0){
			if (dp[0]>d){
				child[0]=ind;
				dp[0]=d;
			}
		}else{
			for (int i=ind-a[ind-1];i<ind;i++){
				if (dp[i+b[i-1]]>d){
					dp[i+b[i-1]]=d;child[i+b[i-1]]=ind;diffs[i+b[i-1]]=i;
					q.push({i+b[i-1],d});
				}
			}
		}
	}
	cout << (dp[0]==1e9?-1:dp[0]) << "\n";
	if (dp[0]!=(1e9)){
		int ind = 0;
		vector<int> jumps; int counts = 0;
		while (true || counts<N){
			if (ind==N) break;
			jumps.pb(diffs[ind]);
			ind=child[ind];
			counts++;
		}
		reverse(jumps.begin(),jumps.end());
		for (int j:jumps) cout << j << " ";
		cout << "\n";
	}
}
