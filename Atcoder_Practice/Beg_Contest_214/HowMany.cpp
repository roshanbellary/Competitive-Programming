#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int S, T;
void solve(){
	ll c = 0;
	for (int i=0;i<=S;i++){
		for (int j=0;j<=S;j++){
			for (int z=0;z<=S;z++){
				if ((i+j+z<=S)&&(i*j*z<=T)) c++;
			}
		}
	}
	cout << c << "\n";
}
int main(){
	setIO();
	cin >> S >> T;
	solve();
}
