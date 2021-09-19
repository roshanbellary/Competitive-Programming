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
int N,M;
vector<int> edges[(int)1e5];
vector<int> in[(int)1e5];
vector<int> out[(int)1e5];
int numin[(int)1e5];
int numEdges[(int)1e5];
bool isfree[(int)1e5];
bool isroot[(int)1e5];
void dfs(int i,int p){
	if(out[i].size() > 0)
		return;
	isroot[i] = 1;
	for(int j=0;j<edges[i].size();j++){
		if(edges[i][j] != p){
			dfs(edges[i][j], i);
		}
	}
}
int main(){
	setIO("gathering");
	cin >> N >> M;
	int a,b;
	for(int i=1;i<N;i++){
		cin >> a >> b;
		edges[--a].push_back(--b);
		edges[b].push_back(a);
		numEdges[a]++, numEdges[b]++;
	}
	for(int i=0;i<M;i++){
		cin >> a >> b;
		in[--b].push_back(--a);
		out[a].push_back(b);
		numin[b]++;
	}
	vector<int> rnodes;
	for(int i=0;i<N;i++)
		if(numEdges[i]<=1 && numin[i]==0){
			rnodes.push_back(i);
			isfree[i] = 1;
		}
	for(int i=0;i<N-1;i++){
		if(i == rnodes.size()){
			for(int j=0;j<N;j++)
				cout << 0 << '\n';
			return 0;
		}
		int cur = rnodes[i];
		for(int j=0;j<edges[cur].size();j++){
			int e = edges[cur][j];
			numEdges[e]--;
			if(numEdges[e]<=1 && numin[e]==0 && !isfree[e]){
				rnodes.push_back(e);
				isfree[e] = 1;
			}
		}
		for(int j=0;j<out[cur].size();j++){
			int e = out[cur][j];
			numin[e]--;
			if(numEdges[e]<=1 && numin[e]==0 && !isfree[e]){
				rnodes.push_back(e);
				isfree[e] = 1;
			}
		}
	}
	int root = rnodes[N-1];
	dfs(root, -1);
	for(int i=0;i<N;i++){
		cout << isroot[i] << '\n';
	}
}