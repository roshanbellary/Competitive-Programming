/*
SZKOpul Task Similarity (sim)
https://szkopul.edu.pl/problemset/problem/PCuJ6tMOmD2CMeBGIx-FKUKr/site/?key=statement
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
string p,t;
vector<ll> c(26,0);
int main(){
	setIO();
	cin >> p >> t;
	ll sum = 0;
	for (int i=0;i<=t.length()-p.length();i++){
		if (i<p.length()){
			c[p[i]-'a']++;
		}
		sum+=c[t[i]-'a'];
	}
	for (int i=t.length()-p.length()+1;i<t.length();i++){
		c[p[p.length()-1-(t.length()-i)]-'a']--;
		sum+=c[t[i]-'a'];
	}
	cout << sum << "\n";
}
