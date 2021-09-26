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
ll K;
string A, B;
int main(){
	setIO();
	cin >> K >> A >> B;
	ll na = 0, nb = 0;
	for (int i=0;i<A.length();i++){
		na+=pow(K,(A.length()-1-i))*(A[i]-'0');
	}
	for (int i=0;i<B.length();i++){
		nb+=pow(K,(B.length()-1-i))*(B[i]-'0');
	}
	cout << na*nb << "\n";
}
