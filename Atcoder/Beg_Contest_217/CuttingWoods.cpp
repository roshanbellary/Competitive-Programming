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
int L, Q;
int main(){
	setIO();
	cin >> L >> Q;
	set<int> c;
	for (int i=0;i<Q;i++){
		int t, x;
		cin >> t >> x;
		if (t==1){
			c.insert(x);
		}else{
			if (c.size()==0){
				cout << L << "\n";
			}else{
				auto itr = c.upper_bound(x);
				auto itr2 = c.upper_bound(x);
				if (itr==c.begin()){
					cout << *itr << "\n";
				}else if (itr==c.end()){
					itr2--;
					cout << L-*itr2 << "\n";
				}else{
					itr2--;
					cout << *itr-*itr2 << "\n";
				}
			}
		}
	}
}
