//Bulding Teams-CSES Graph Algorithms
//https://cses.fi/problemset/task/1668/
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
int col[(int)1e5];
vector<int> l[(int)1e5];
bool w = true;
void dfs(int i, int c){
	col[i]=c;
	for (int j:l[i]){
		if (col[j]==c){
			w=false;
		}else if (col[j]==0){
			if (c==1) dfs(j,2);
			else dfs(j,1);
		}
	}
}
int main(){
	setIO();
	cin >> N >> M;
	for (int i=0;i<M;i++){
		int a, b; cin >> a >> b;
		l[--a].pb(--b);l[b].pb(a);
	}
	for (int i=0;i<N;i++){
		if (col[i]==0){
			dfs(i,1);
		}
	}
	if (!w){cout << "IMPOSSIBLE\n";return 0;}
	for (int i=0;i<N;i++){
		cout << col[i] << " ";
	}
	cout << "\n";
}
