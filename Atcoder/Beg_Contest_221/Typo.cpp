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
int sc[26];
int tc[26];
string s,t;
int main(){
	setIO();
	memset(sc,0,sizeof(sc));memset(tc,0,sizeof(tc));
	cin >> s; cin >> t;
	int diff=0;
	for (int i=0;i<s.length();i++){
		if (s[i]!=t[i]) diff++;
	}
	if (diff==0){cout << "Yes\n"; return 0;}
	if (diff!=2){cout << "No\n";return 0;}
	for (int i=0;i<s.length()-1;i++){
		if (s[i]!=t[i] && s[i+1]!=t[i+1] && s[i]==t[i+1] && s[i+1]==t[i]) {cout << "Yes\n";return 0;}
	}
	cout << "No\n";return 0;
}
