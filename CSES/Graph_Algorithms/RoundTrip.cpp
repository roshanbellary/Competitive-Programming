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
bool tv[(int)1e5];
stack<int> ord;
vector<int> route;
bool cycle = false;
void dfs(int i, int p){
	if (cycle) return;
	v[i]=true;route.pb(i);tv[i]=1;
	for (int j:l[i]){
		if (cycle) break;
		if (j==p) continue;
		if (!v[j]){
			dfs(j,i);
		}else{
			route.pb(j);cycle=1;
			break;
		}
	}
	if (cycle) return;
	v[i]=0;
	route.pop_back();
}
int main(){
	setIO();
	cin >> N >> M;
	for (int i=0;i<M;i++){
		int a, b; cin >> a >> b;
		l[--a].pb(--b);
		l[b].pb(a);
	}
	for (int i=0;i<N;i++){
		if (cycle) break;
		if (!tv[i]){
			route.clear();
			dfs(i,i);
		}
	}
	if (!cycle) cout << "IMPOSSIBLE\n";
	int j = -1;
	for (int i=route.size()-2;i>=0;i--){
		if (route[i]==route.back()){j=i;break;}
	}
	cout << route.size()-j << "\n";
	for (int i=j;i<route.size();i++){
		cout << route[i]+1 << " ";
	}
	cout << "\n";
}
