//Bulding Roads-CSES Graph Algorithms
//https://cses.fi/problemset/result/2902998/
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
bool v[(int)1e5];
void dfs(int i){
	v[i]=true;
	for (int j:l[i]){
		if (!v[j]) dfs(j);
	}
}
int main(){
	setIO();
	cin >> N >> M;
	for (int i=0;i<M;i++){
		int a,b; cin>> a >> b;
		l[--a].pb(--b);
		l[b].pb(a);
	}
	int roads=-1;
	vector<int> comp;
	for (int i=0;i<N;i++){
		if (!v[i]){
			roads++;
			dfs(i);
			comp.pb(i);
		}
	}
	cout << roads << "\n";
	for (int i=0;i<comp.size()-1;i++){
		cout << comp[i]+1 << " " << comp[i+1]+1 << "\n";
	}
}
