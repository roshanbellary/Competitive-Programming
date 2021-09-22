/*
CCO '18 P4 - Gradient Descent
https://dmoj.ca/problem/cco18p4
Cool problem with binary searches to find a median
*/
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
int mod = 1e9+7;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
ll R, C;
int K;
ll query(ll x, ll y){
	cout << "? " << x << " " << y << endl;
	ll score; cin >> score;
	return score;
}
int main(){
	setIO();
	cin >> R >> C >> K;
	ll l=1,r=R;
	while (l!=r){
		ll mid=(l+r)/2;
		ll res2 = query(mid+1,1);
		ll res1 = query(mid,1);
		if (res2>res1){
			r=mid;
		}else if (res2<res1){
			l=mid+1;
		}else{
			l=mid;r=mid;
			break;
		}
	}
	ll xc = l;
	l=1;r=C;
	while (l!=r){
		ll mid=(l+r)/2;
		ll res2 = query(1,mid+1);
		ll res1 = query(1,mid);
		if (res2>res1){
			r=mid;
		}else if (res2<res1){
			l=mid+1;
		}else{
			l=mid;r=mid;
			break;
		}
	}
	ll yc=l;
	cout << "? " << xc << " " << yc << endl;
	ll score; cin >> score;
	cout << "! " << score << endl;
}
