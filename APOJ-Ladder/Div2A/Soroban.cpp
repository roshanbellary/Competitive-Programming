#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
}
void setIO(string f){
	string in = f+".in";
	string out = f+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	setIO();
}
void solve(int N){
	string s = to_string(N);
	int l = s.length();
	for (int i=l-1;i>=0;i--){
		int dig = s[i]-'0';
		if (dig>=5){
			cout << "-O|";
		}else{
			cout << "O-|";
		}
		for (int i=0;i<dig%5;i++){
			cout << "O";
		}
		cout << "-";
		for (int i=0;i<4-dig%5;i++){
			cout << "O";
		}
		cout << "\n";
	}
}
int main(){
	setIO();
	int N;cin >> N;
	solve(N);
}
