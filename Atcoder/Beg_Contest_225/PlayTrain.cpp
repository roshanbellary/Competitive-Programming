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
int N, Q,parent[(int)1e5],child[(int)1e5];
int findRoot(int u){
	if (parent[u]==u){
		return u;
	}else{
		return findRoot(parent[u]);
	}
}
void combine(int u, int v){
	child[u]=v;
	parent[v]=u;
}
void separate(int u, int v){
	parent[v]=v;
	child[u]=u;
}
void printComponent(int u){
	int st = findRoot(u);
	vector<int> v;
	while (true){
		v.pb(st+1);
		int p = child[st];
		if (p==st) break;
		st=p;
	}
	cout << v.size() << " ";
	for (int j:v) cout << j << " ";
	cout << "\n";
}
int main(){
	setIO();cin >> N >> Q;
	for (int i=0;i<N;i++){
		parent[i]=i;child[i]=i;
	}
	for (int i=0;i<Q;i++){
		int t; cin >> t;
		if (t==1){
			int x, y; cin >> x >> y;combine(--x,--y);
		}else if (t==2){
			int x, y; cin >> x >> y;separate(--x,--y);
		}else{
			int x; cin >> x;printComponent(--x);
		}
	}
}
