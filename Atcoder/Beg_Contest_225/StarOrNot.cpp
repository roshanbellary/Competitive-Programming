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
int N,e[(int)1e5];
int main(){
	setIO();cin >> N;
	for (int i=0;i<N-1;i++){
		int u,v; cin >> u >> v;
		e[--u]++;e[--v]++;
	}
	for (int i=0;i<N;i++){
		if (e[i]==N-1){
			cout << "Yes\n";return 0;
		}
	}
	cout << "No\n";
}
