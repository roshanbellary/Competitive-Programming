//Message Route - CSES Graph Algorithms
//https://cses.fi/problemset/task/1667/
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
int N, M;
vector<int> l[(int)2e5];
int dist[(int)2e5];
vector<int> route;
void dfs(int i){
	route.pb(i);
	for (int j:l[i]){
		if (dist[j]==dist[i]-1){
			dfs(j);
			return;
		}
	}
}
int main(){
	setIO();
	cin >> N >> M;
	for (int i=0;i<N;i++) dist[i]=1e9;
	for (int i=0;i<M;i++){
		int a, b; cin >> a >> b;
		l[--a].pb(--b);
		l[b].pb(a);
	}
	dist[0]=0;
	queue<int> q;
	q.push(0);
	while (!q.empty()){
		int ind = q.front();
		q.pop();
		for (int j:l[ind]){
			if (dist[j]>dist[ind]+1){
				dist[j]=dist[ind]+1;
				q.push(j);
			}
		}
	}
	if (dist[N-1]==1e9){cout << "IMPOSSIBLE\n";return 0;}
	dfs(N-1);
	cout << dist[N-1]+1 << "\n";
	for (int i=route.size()-1;i>=0;i--){
		cout << route[i]+1 << " ";
	}
	cout << "\n";
}
