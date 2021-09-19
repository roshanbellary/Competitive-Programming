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
ll solve(ll n2, ll n3, ll n4){
	ll sticks = 0;
	sticks+=min(n3/2,n4);//2*3+4
	ll mini = min(n3/2,n4);
	n3-=2*mini;n4-=mini;

	mini = min(n3/2,n2/2);
	sticks+=mini;//2*3+2*2
	n3-=2*mini;n2-=2*mini;

	mini=min(n4/2,n2);
	sticks+=mini;//2*4+2
	n4-=2*mini;n2-=mini;

	mini = min(n2/3,n4);
	sticks+=mini;//3*2+4
	n2-=3*mini;n4-=mini;

	sticks+=n2/5;//5*2
	n2%=5;
	return sticks;
}
int T;
int main(){
	setIO();
	cin >> T;
	for (int l=0;l<T;l++){
		ll n2,n3,n4;
		cin >> n2 >> n3 >> n4;
		cout << solve(n2,n3,n4) << "\n";
	}
}
