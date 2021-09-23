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
int main(){
	setIO();
	cin >> N >> K;
	for (int i=0;i<N;i++){cin >> t[i];t[i]=(t[i]+11)/12;}
	sort(t,t+N);
	vector<int> d;
	for (int i=0;i<N-1;i++){
		d.pb(t[i+1]-t[i]);
	}
	sort(d.begin(),d.end(),greater<int>());
	ll dist = 0;
	for (int i=K-1;i<d.size();i++){
		dist+=d[i]*12;
	}
	dist+=(K)*12;
	cout << dist << "\n";
}
