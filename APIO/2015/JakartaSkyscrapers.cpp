#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
#define int long long
#define pb push_back
#define eb emplace_back
#define countbits __builtin_popcount
#define beg0 __builtin_clz
#define terminal0 __builtin_ctz
int mod = 1e9+7;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N, M;
vector<vector<pair<int,int>>> l;
vector<pair<int,int>> m;
int32_t main(){
	setIO();
	cin >> N >> M;
	for (int i=0;i<M;i++) l.pb(vector<pair<int,int>>());
	for (int i=0;i<M;i++){
		int pos; cin >> pos;
		int moves; cin >> moves;
		m.pb({pos,moves});
	}
	for (int i=0;i<M;i++){
		for (int j=0;j<M;j++){
			if (i==j) continue;
			if (abs(m[j].first-m[i].first)%m[i].second==0){
				l[i].pb({j,abs(m[j].first-m[i].first)/m[i].second});
			}
		}
	}
	int dp[M];
	for (int i=0;i<M;i++){dp[i]=1e9;}
	priority_queue<pair<int,int>> pq;
	pq.push({0,0});
	while (!pq.empty()){
		int dist = -pq.top().first;
		int ind = pq.top().second;
		pq.pop();
		for (pair<int,int> a:l[ind]){
			if (dp[a.first]>a.second+dist){
				dp[a.first]=a.second+dist;
				pq.push({-(a.second+dist),a.first});
			}
		}
	}
	if (dp[1]==1e9){
		cout << "-1\n";
	}else cout << dp[1] << "\n";
}
