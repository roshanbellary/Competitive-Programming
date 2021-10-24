//#pragma GCC optimize("O2")
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
ll N,col[(int)2e5],st[(int)2e5];
vector<int> l[(int)2e5];
void stree(int ind){
	st[ind]=1;
	for (int j:l[ind]){
		stree(j);st[ind]+=st[j];
	}
}
void dfs(int ind){
	col[ind]=1;
	for (int j:l[ind]){
		dfs(j); col[ind]+=(st[j]+col[j]);
	}
}
int main(){
	setIO(); cin >> N;
	for (int i=0;i<N-1;i++){
		int v; cin >> v;
		l[--v].pb(i+1);
	}
	stree(0);dfs(0);
	for (int i=0;i<N;i++) cout << col[i] << " ";
	cout << "\n";
}
