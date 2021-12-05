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
int N, K;
int t[65536];
vector<ll> d;
int main(){
	setIO();
	cin >> N >> K;
	for (int i=0;i<N;i++){cin >> t[i];}
	sort(t,t+N);
	ll p = -1,n = 0;
	bool zero = 0;
	for (int i=0;i<N;i++){
		if (t[i]/12==p){if (zero) n+=12,zero=0;}
		else if (t[i]/12==p+1){
			if (t[i]%12==0) continue;
			else{n+=12;p++;zero=0;}
		}else{
			d.pb(t[i]/12-p-1);p=t[i]/12;
			if (t[i]%12!=0){
				n+=12;zero=0;
			}else{
				zero=1;
			}
		}
	}
	sort(d.begin(),d.end());
	if (d.size()>=K){
		for (int i=0;i<=d.size()-K;i++){
			n+=12*d[i];
		}
	}
	cout << n << "\n";
}
