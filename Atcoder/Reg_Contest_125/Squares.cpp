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
ll N;
int mod = 998244353;
int main(){
	setIO();
	cin >> N;
	ll sum = 0;
	for (ll i=1;i<=sqrt(N);i++){
		if (N/i-i<0) break;
		sum+=((N/i-i)/2+1);
	}
	cout << sum%mod << "\n";
}
