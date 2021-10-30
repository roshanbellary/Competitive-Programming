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
ll N, M,pump[(int)5e5],c[(int)1e5];
vector<pair<int,int>> l[(int)1e5];
bool cyc = false,v[(int)1e5];
void dfs2(int ind, int p){
	if (cyc) return;
	v[ind]=true;
	for (pair<int,int> j:l[ind]){
		if (cyc) break;
		if (j.first==p) continue;
		if (v[j.first]){cyc=true;return;}
		else{
			dfs2(j.first,ind);
		}
	}
}
ll dfs(int ind, int p){
	v[ind]=true;
	ll val = c[ind];
	for (pair<int,int> j:l[ind]){
		if (j.first==p) continue;
		pump[j.second]=dfs(j.first,ind);
		val-=pump[j.second];
	}
	return val;
}
int main(){
	setIO(); cin >> N >> M;
	for (int i=0;i<N;i++) cin >> c[i];
	for (int i=0;i<M;i++){
		int u,v; cin >> u >> v;
		l[--u].pb({--v,i});
		l[v].pb({u,i});
	}
	for (int i=0;i<N;i++){
		if (!v[i]) dfs2(i,i);
	}
	if (cyc){cout << "0\n";return 0;}
	memset(v,0,sizeof(v));
	for (int i=0;i<N;i++){
		if (!v[i]) dfs(i,i);
	}
	for (int i=0;i<M;i++){
		cout << 2*pump[i] << "\n";
	}
}