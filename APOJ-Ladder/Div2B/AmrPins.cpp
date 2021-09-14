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
	ll R, SX, SY, FX, FY;
	cin >> R >> SX >> SY >> FX >> FY;
	double d = sqrt(abs(FX-SX)*abs(FX-SX)+abs(FY-SY)*abs(FY-SY));
	cout << ceil(d/(2*R)) << "\n";
}
