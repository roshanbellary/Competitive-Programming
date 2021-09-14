#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
}
void setIO(string f){
	string in = f+".in";
	string out = f+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	setIO();
}
int N, Q;
int main(){
	setIO();
	cin >> N >> Q;
	ll v[N];
	for (int i=0;i<N;i++){
		cin >> v[i];
	}
	for (int i=0;i<Q;i++){
		ll k; cin >> k;
		int s = 0;
		int f = N-1;
		while (s!=f){
			int mid = (s+f+1)/2;
			if (v[mid]-mid-1<k){
				s=mid;
			}else{
				f=mid-1;
			}
		}
		if (v[s]-s-1>=k){
			cout << k << "\n";
		}else cout << v[s]+(k-v[s]+s+1) << "\n";
	}
}
