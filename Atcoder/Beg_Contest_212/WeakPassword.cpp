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
int main(){
	setIO();
	string s; cin >> s;
	int d[4];
	for (int i=0;i<4;i++) d[i]=(s[i]-'0');
	bool same = true;
	int val = d[0];
	for (int i=0;i<4;i++){
		if (d[i]!=val){same=false;break;}
	}
	bool follow = true;
	for (int i=0;i<3;i++){
		if (d[i+1]!=(d[i]+1)%10){follow=false;break;}
	}
	if (same||follow) cout << "Weak\n";
	else cout << "Strong\n";
}
