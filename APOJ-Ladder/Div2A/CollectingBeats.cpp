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
int K;
int main(){
	setIO();
	cin >> K;
	map<int,int> m;
	set<int> n;
	for (int i=0;i<4;i++){
		string s; cin >> s;
		for (int j=0;j<4;j++){
			if (s[j]!='.'){
				n.insert(s[j]-'0');
				m[s[j]-'0']++;
			}
		}
	}
	bool w = true;
	for (int j:n){
		if (m[j]>2*K){w=false;break;}
	}
	if (w) cout << "YES\n";
	else cout << "NO\n";
}
