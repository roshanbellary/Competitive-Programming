/*
USACO 2014 February Contest, Gold Problem 2. Cow Decathlon
http://www.usaco.org/index.php?page=viewproblem2&cpid=401
Part of the reason why I spent too much time on this problem was me misreading the question in 
regards to the addition of goal points to the cows points. I was able to solve this problem 
once I realized my misunderstanding.
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
class Goal{
	public:
		int k, p, a;
};
vector<Goal> g;
int N, B;int s[20][20];
int dp[1<<20];
int main(){
	setIO("dec");
	cin >> N >> B;
	for (int i=0;i<(1<<N);i++) dp[i]=-1;
	for (int i=0;i<B;i++){
		Goal n; cin >> n.k >> n.p >> n.a;
		g.pb(n);
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			cin >> s[i][j];
		}
	}
	for (int i=0;i<N;i++){
		dp[(1<<i)]=s[i][0];
	}
	for (int i=1;i<(1<<N);i++){//1e6
		if (dp[i]>=0) continue;
		int bits = countbits(i);
		for (int j=0;j<N;j++){//20
			if (i&(1<<j)){
				int add = s[j][bits-1];
				int n = (i&(~(1<<j)));
				dp[i]=max(dp[n]+add,dp[i]);
			}
		}
		for (int j=0;j<B;j++){
			if (g[j].k==bits && dp[i]>=g[j].p){
				dp[i]+=g[j].a;
			}
		}
	}
	int maxV = 0;
	for (int i=1;i<(1<<N);i++){
		maxV=max(maxV,dp[i]);
	}
	cout << maxV << "\n";
}
