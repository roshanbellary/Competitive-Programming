#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int main(){
	setIO();
	int T; cin >> T;
	for (int l=0;l<T;l++){
		int N; cin >> N;
		vector<ll> w(N);
		for (int i=0;i<N;i++) cin >> w[i];
		set<ll> val;
		for (int i=0;i<N;i++){
			val.insert(w[i]-(i+1));
		}
		if (val.size()==1){
			cout << N << "\n";
		}else if (val.size()>1){
			cout << 1 << "\n";
		}
	}
}
