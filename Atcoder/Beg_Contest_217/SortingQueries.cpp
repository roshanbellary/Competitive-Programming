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
int Q;
int main(){
	setIO();
	cin >> Q;
	multiset<int> v;
	deque<int> d;
	for (int i=0;i<Q;i++){
		int t; cin >> t;
		if (t==1){
			int x; cin >> x;
			d.push_back(x);
		}else if (t==2){
			if (v.size()){
				cout << *v.begin() << "\n";
				v.erase(v.begin());
			}else{
				cout << d.front() << "\n";
				d.pop_front();
			}
		}else{
			while (d.size()){
				v.insert(d.front());
				d.pop_front();
			}
		}
	}
}
