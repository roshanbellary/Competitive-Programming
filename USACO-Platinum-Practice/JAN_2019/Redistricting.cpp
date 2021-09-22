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
int N, K;
bool t[(int)3e5];
int m[(int)3e5+1],dp[(int)3e5+1];
multiset<int> inc[(int)3e5+1];
int main(){
	setIO("redistricting");
	cin >> N >> K;
	string d; cin >> d;
	for (int i=0;i<N;i++)t[i]=(d[i]=='H');
	m[0]=0;
	for (int i=1;i<=N;i++){
		if (t[i-1]) m[i]=m[i-1]+1;
		else m[i]=m[i-1]-1;
	}
	dp[0]=0;
	multiset<int> vals; vals.insert(0);
	inc[0].insert(0);
	for (int i=1;i<=N;i++){
		int mval = *vals.begin();
		if (*inc[mval].begin()<m[i]){
			dp[i]=mval;
		}else dp[i]=mval+1;
		vals.insert(dp[i]);
		inc[dp[i]].insert(m[i]);
		if (i>=K){
			vals.erase(vals.find(dp[i-K]));
			inc[dp[i-K]].erase(inc[dp[i-K]].find(m[i-K]));
		}
	}
	cout << dp[N] << "\n";
}
