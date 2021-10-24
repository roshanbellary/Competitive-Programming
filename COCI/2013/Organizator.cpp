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
int N;
int col[(int)2e6+1];
int val[(int)2e6+1];
int main(){
	setIO(); cin >> N;
	for (int i=0;i<N;i++){
		int v; cin >> v; val[v]++;
	}
	for (int i=1;i<=2e6;i++){
		for (int k=1;k<=2e6/i;k++){
			col[i]+=val[k*i];
		}
	}
	ll maxV = 0;
	for (ll i=1;i<=2e6;i++){
		if (col[i]>=2) maxV=max(col[i]*(ll)i,maxV);
	}
	cout << maxV << "\n";
}
