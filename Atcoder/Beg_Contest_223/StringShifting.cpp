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
int mod=1e9+7;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
string s[1000];
string w;
int main(){
	setIO();cin >> w;
	int c = 0; string store=w;;
	while (c<w.length()){
		store=w;
		w=w.substr(c+1)+w.substr(0,c+1);
		s[c]=w;c++; w=store;
	}
	sort(s,s+w.length());
	cout << s[0] << "\n" << s[w.length()-1] << "\n";
}
