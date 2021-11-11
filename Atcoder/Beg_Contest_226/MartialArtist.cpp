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
#define f first
#define s second
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
ll N, K, t[(int)2e5], dp[(int)2e5];
bool v[(int)2e5];
vector<int> l[(int)2e5];
vector<int> ord;
void dfs(int ind){
	v[ind]=true;
	for (int j:l[ind]){
		if (!v[j]) dfs(j);
	}
	ord.pb(ind);
}
int main(){
	setIO(); cin >> N;memset(dp,0,sizeof(dp));
	for (int i=0;i<N;i++){
		cin >> t[i]; cin >> K;
		for (int j=0;j<K;j++){
			int v; cin >> v;l[i].pb(--v);
		}
	}
	dfs(N-1);reverse(ord.begin(),ord.end());
	ll time = 0;
	for (int j:ord){
		time+=t[j];
	}
	cout << time << "\n";
}
