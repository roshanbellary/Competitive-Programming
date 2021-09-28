/*
USACO 2015 January Contest, Gold Problem 3. Grass Cownoisseur
http://usaco.org/index.php?page=viewproblem2&cpid=516
Solved with Editorial It was hard to account for cycles that don't include vertex 1. 
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
int N, M;
vector<int> l[(int)1e5];
int low[(int)1e5];
int tin[(int)1e5];
bool vis[(int)1e5];
int comps[(int)1e5];
vector<vector<int>> fl;
vector<vector<int>> bl;
vector<int> ns;
stack<int> v;
int timer = 0;
int scomps = 0;
void dfs(int i, int p){
	vis[i]=true;
	tin[i]=timer;
	low[i]=timer;
	v.push(i);timer++;
	for (int j:l[i]){
		if (j==p) continue;
		if (!vis[j]){
			dfs(j,p);
			low[i]=min(low[j],low[i]);
		}else{
			low[i]=min(low[j],low[i]);
		}
	}
	if (low[i]==tin[i] && v.size()>0){
		ns.pb(0);
		ns[ns.size()-1]++;
		comps[i]=scomps;
		while (!v.empty() && v.top()!=i){
			ns[ns.size()-1]++;
			comps[v.top()]=scomps;
			v.pop();
		}
		scomps++;
	}
}
int d1[(int)1e5];
int d2[(int)1e5];
int main(){
	setIO();
	cin >> N>> M;
	for (int i=0;i<M;i++){
		int a,b; cin >> a >> b;
		l[--a].pb(--b);
	}
	cout << "\n";
	for (int i=0;i<N;i++){
		if (!vis[i]) dfs(i,i);
	}
	for (int i=0;i<scomps;i++){
		fl.pb(vector<int>());
		bl.pb(vector<int>());
		vis[i]=false;
	}
	for (int i=0;i<N;i++){
		for (int j:l[i]){
			if (comps[i]!=comps[j]){
				fl[comps[i]].pb(comps[j]);
				bl[comps[j]].pb(comps[i]);
			}
		}
	}
	int mcomp = comps[0];
	priority_queue<pair<int,int>> pq;
	d1[mcomp]=ns[mcomp];
	pq.push({ns[mcomp],mcomp});
	while (!pq.empty()){
		int ind = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (d>=d1[ind]) continue;
		d1[ind]=d;
		for (int j:fl[ind]){
			if (d+ns[j]>d1[j]){
				d1[j]=d+ns[j];
				pq.push({d+ns[j],j});
			}
		}
	}
	d2[mcomp]=ns[mcomp];
	pq.push({ns[mcomp],mcomp});
	while (!pq.empty()){
		int ind = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (d>=d2[ind]) continue;
		d2[ind]=d;
		for (int j:bl[ind]){
			if (d+ns[j]>d2[j]){
				d2[j]=d+ns[j];
				pq.push({d+ns[j],j});
			}
		}
	}
	int maxs = ns[mcomp];
	for (int i=0;i<scomps;i++){
		if (d1[i]>0){
			for (int j:fl[i]){
				if (d2[j]>0){
					maxs=max(maxs,d1[i]+d2[j]-ns[mcomp]);
				}
			}
		}
	}
	cout << maxs << "\n";
}
