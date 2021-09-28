/*
USACO 2012 December Contest, Gold
Problem 3. Running Away From the Barn
http://www.usaco.org/index.php?page=viewproblem2&cpid=213
Cool problem about merging small to large!
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
#define int long long
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
ll N, L;
vector<vector<pair<ll,ll>>> l;
vector<multiset<ll>> reach;
vector<int> num(2e5,0);
vector<ll> dist(2e5,0);
void dfs1(int i, int p, ll d){
	dist[i]=d;
	for (pair<ll,ll> j:l[i]){
		if (j.first!=p){
			dfs1(j.first,i,d+j.second);
		}
	}
}
void dfs(int i, int p){
	if (l[i].size()==1){
		num[i]=1;
		reach[i].insert(dist[i]);
	}else{
		reach[i].insert(dist[i]);
		int maxi = 0; int pos = -1;
		for (int j=0;j<l[i].size();j++){
			if (l[i][j].first==p) continue;
			dfs(l[i][j].first,i);
			if (reach[l[i][j].first].size()>maxi){maxi=reach[l[i][j].first].size(); pos=j;}
		}
		swap(reach[l[i][pos].first],reach[i]);
		for (pair<ll,ll> j:l[i]){
			if (j.first==p) continue;
			for (ll k:reach[j.first]){
				reach[i].insert(k);
			}
		}
		ll upper = L+dist[i];
		auto itr = reach[i].upper_bound(upper);
		if (itr!=reach[i].end()){
			reach[i].erase(itr,reach[i].end());
		}
		num[i]=reach[i].size();
	}
}
int32_t main(){
	setIO("runaway");
	cin >> N >> L;
	for (int i=0;i<N;i++){
		l.pb(vector<pair<ll,ll>>());
		reach.pb(multiset<ll>());
	}
	for (int i=0;i<N-1;i++){
		ll c, le; cin >> c >> le; c--;
		l[c].pb(make_pair(i+1,le));
		l[i+1].pb(make_pair(c,le));
	}
	dfs1(0,0,0);
	dfs(0,0);
	for (int i=0;i<N;i++){
		cout << num[i] << "\n";
	}
}
