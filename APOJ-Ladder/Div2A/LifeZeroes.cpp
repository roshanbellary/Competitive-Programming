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
	string a,b;
	cin >> a >> b;
	string c = to_string(stoi(a)+stoi(b));
	string na="";
	string nb="";
	string nc="";
	for (int i=0;i<a.length();i++){
		if (a[i]=='0') continue;
		else na+=a[i];
	}
	for (int i=0;i<b.length();i++){
		if (b[i]=='0') continue;
		else nb+=b[i];
	}
	for (int i=0;i<c.length();i++){
		if (c[i]=='0') continue;
		else nc+=c[i];
	}
	if (stoi(na)+stoi(nb)==stoi(nc)) cout << "YES\n";
	else cout << "NO\n";
}
