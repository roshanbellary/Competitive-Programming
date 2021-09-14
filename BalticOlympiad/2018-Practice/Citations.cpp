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
int N;
int r[100001];
int c[100001];
vector<vector<int>> l;
pair<ll,int> dfs(int i){
	pair<ll,int> res={0,1};
	vector<pair<ll,int>> nodes;
	for (int j:l[i]){
		nodes.pb(dfs(j));
	}
	sort(nodes.begin(),nodes.end());
	ll cumsum = 0;
	for (pair<ll,int> j:nodes){
		cumsum+=(j.first+j.second*(j.second+1)/2);
		res.first+=(cumsum*j.second);
		res.second+=j.second;
	}
	res.first=2*res.first+r[i];
	return res;
}
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++) l.pb(vector<int>());
	for (int i=0;i<N;i++){
		int t; cin >> t;
		r[i]=t;
		int n; cin >> n;
		for (int j=0;j<n;j++){
			int v; cin >> v;
			l[i].pb(v);
		}
	}
	cout << dfs(0).first-3 << "\n";
}
