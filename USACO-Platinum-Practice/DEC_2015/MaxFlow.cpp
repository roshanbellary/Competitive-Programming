/*
USACO 2015 December Contest, Platinum Problem 1. Max Flow
http://www.usaco.org/index.php?page=viewproblem2&cpid=576
Spent too much time debugging but overall I found the algorithm easily.
*/
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
int N, K;
vector<vector<int>> l;
vector<int> parent;
vector<int> depth;
vector<vector<int>> ancestor;
vector<int> col;
int maxn = 0;
void dfs(int i, int p, int d){
	parent[i]=p;
	depth[i]=d;
	for (int j=0;j<l[i].size();j++){
		if (l[i][j]==p) continue;
		dfs(l[i][j],i,d+1);
	}
}
int lca(int v1, int v2){
	int n1 = v1; int n2 = v2;
	if (depth[n1]>depth[n2]) swap(n1,n2);
	int diff = depth[n2]-depth[n1];
	for (int i=0;i<log2(N);i++){
		if (diff&(1<<i)){
			n2=ancestor[n2][i];
		}
	}
	if (n1==n2){return n1;}
	for (int i=log2(N)-1;i>=0;i--){
		if (ancestor[n1][i]!=ancestor[n2][i]){
			n1=ancestor[n1][i];
			n2=ancestor[n2][i];
		}
	}
	return parent[n1];
}
void dfs2(int i, int p){
	for (int j=0;j<l[i].size();j++){
		if (l[i][j]==p) continue;
		dfs2(l[i][j],i);
		col[i]+=col[l[i][j]];
	}
	maxn=max(col[i],maxn);
}
int main(){
	setIO("maxflow");
	cin >> N >> K;
	for (int i=0;i<N;i++){parent.pb(i);depth.pb(0);l.pb(vector<int>());ancestor.pb(vector<int>(ceil(log2(N))+1));col.pb(0);}
	for (int i=0;i<N-1;i++){
		int s, t; cin >> s >> t;s--;t--;
		l[s].pb(t);
		l[t].pb(s);
	}
	dfs(0,0,0);
	for (int i=0;i<N;i++){
		ancestor[i][0]=parent[i];
	}
	for (int k=0;k<log2(N);k++){
		for (int i=0;i<N;i++){
			ancestor[i][k+1]=ancestor[ancestor[i][k]][k];
		}
	}
	for (int i=0;i<K;i++){
		int s,t; cin >> s >> t; s--;t--;
		int p = lca(s,t);
		if (p==s){
			if (parent[s]!=s) col[parent[s]]--;
			col[t]++;
		}else if (p==t){
			if (parent[t]!=t) col[parent[t]]--;
			col[s]++;
		}else{
			if (parent[p]!=p) col[parent[p]]--;
			col[p]--;
			col[s]++;
			col[t]++;
		}
	}
	dfs2(0,0);
	cout << maxn << "\n";
}
