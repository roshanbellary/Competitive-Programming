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
int X, Y;
int main(){
	setIO();
	cin >> X >> Y;
	int N; cin >> N;
	N%=6;
	if (N==0) N=5;
	else N--;
	int a[6]={X,Y,Y-X,-X,-Y,X-Y};
	int mod = 1e9+7;
	cout << (a[N]%mod+mod)%mod << "\n";
}
