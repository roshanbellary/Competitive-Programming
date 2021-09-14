#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
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
priority_queue<tuple<int,int,ll>> pq;
vector<int> parent;
vector<int> sizes;
int findRoot(int v){
	if (v==parent[v]) return v;
	else{
		parent[v]=findRoot(parent[v]);
		return parent[v];
	}
}
void merge(int u, int v){
	u=findRoot(u);v=findRoot(v);
	if (u==v) return;
	if (sizes[v]>sizes[u]) swap(u,v);
	sizes[u]+=sizes[v];
	parent[v]=u;
}
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++){parent.pb(i);sizes.pb(1);}
	for (int i=0;i<N-1;i++){
		ll u, v, w;
		cin >> u >> v >> w;u--;v--;
		pq.push({-w,u,v,});
	}
	ll sum = 0;
	while (!pq.empty()){
		int u = get<1>(pq.top());
		int v = get<2>(pq.top());
		ll w = -get<0>(pq.top());
		pq.pop();
		u=findRoot(u);v=findRoot(v);
		if (u!=v) sum+=((ll)sizes[u]*(ll)sizes[v]*w);
		merge(u,v);
	}
	cout << sum << "\n";
}
