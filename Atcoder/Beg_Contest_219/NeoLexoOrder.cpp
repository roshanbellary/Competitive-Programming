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
string X;
map<char,int> ord;
int N;
string s[(int)5e4];
bool comp(string &a, string &b){
	for (int i=0;i<min(a.length(),b.length());i++){
		if (ord[a[i]]<ord[b[i]]){
			return true;
		}else if (ord[a[i]]>ord[b[i]]){
			return false;
		}
	}
	if (a.length()>b.length()) return false;
	else return true;
}
int main(){
	setIO();
	cin >> X;
	for (int i=0;i<26;i++){
		ord[X[i]]=i;
	}
	cin >> N;
	for (int i=0;i<N;i++){
		cin >> s[i];
	}
	sort(s,s+N,comp);
	for (int i=0;i<N;i++){
		cout << s[i] << "\n";
	}
}
