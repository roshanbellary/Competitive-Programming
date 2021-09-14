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
	string in = f+".in";
	string out = f+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	setIO();
}
ll N, M, C;
vector<pair<int,int>> l;
vector<ll> m;
ll dp[1001][1001];
int main(){
	setIO("time");
	cin >> N >> M >> C;
	for (int i=0;i<1001;i++){
		for (int j=0;j<N;j++){
			dp[i][j]=(-1e17);
		}
	}
	for (int i=0;i<N;i++){
		int v; cin >> v;
		m.push_back(v);
	}
	for (int i=0;i<M;i++){
		int c1, c2; cin >> c1 >> c2;
		c1--;c2--;
		l.push_back(make_pair(c1,c2));
	}
	dp[0][0]=0;
	ll totmax = 0;
	for (int t=1;t<=1000;t++){
		for (int i=0;i<M;i++){
			dp[t][l[i].second]=max(dp[t-1][l[i].first]+m[l[i].second],dp[t][l[i].second]);
		}
		totmax=max(dp[t][0]-C*t*t,totmax);
	}
	cout << totmax << "\n";
}
