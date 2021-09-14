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
ll N;
int main(){
	setIO();
	cin >> N;
	ll l = log2(N);
	string s;
	bool p = false;
	for (int i=l;i>=0;i--){
		if ((N&(1LL<<i))!=0){
			s+="A";
		}else{
			s+="B";
		}
	}
	for (int i=s.length()-1;i>=0;i--){
		if ((s[i]=='A')&&(i!=0)){
			s=s.substr(0,i)+"B"+s.substr(i);
		}
	}
	cout << s << "\n";
}