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
pair<ll,ll> v[500000];
int N;
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++){
		cin >> v[i].first >> v[i].second;
	}
	sort(v,v+N);
	ll col = 0;
	ll totval = -1e18;
	ll maxV = -1e18;
	int pos = -1;
	for (int i=0;i<N;i++){
		col+=v[i].second;
		if (col-(v[i].first-v[0].first)>=maxV){
			pos=i;
			maxV=col-(v[i].first-v[0].first);
		}
	}
	col=0;
	for (int i=0;i<=pos;i++){
		col+=v[i].second;
	}
	for (int i=0;i<=pos;i++){
		totval=max(totval,col-(v[pos].first-v[i].first));
		col-=v[i].second;
	}
	cout << totval << "\n";
}
