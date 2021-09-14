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
int H, W;
ll C;
const int s = 1001;
ll v[s][s];
ll dp1[s][s];
ll dp2[s][s];
int main(){
	setIO();
	cin >> H >> W >> C;
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			cin >> v[i][j];
		}
	}
	for (int i=H-1;i>=0;i--){
		for (int j=W-1;j>=0;j--){
			ll totmin = 1e18;
			for (int k=i+1;k<H;k++){
				totmin=min(totmin,min(dp1[k][j],v[k][j])+C*(k-i));
			}
			for (int k=j+1;k<W;k++){
				totmin=min(totmin,min(dp1[i][k],v[i][k])+C*(k-j));
			}
			dp1[i][j]=totmin;
		}
	}
	for (int i=H-1;i>=0;i--){
		for (int j=0;j<W;j++){
			ll totmin=1e18;
			for (int k=i+1;k<H;k++){
				totmin=min(totmin,min(dp2[k][j],v[k][j])+C*(k-i));
			}
			for (int k=0;k<j;k++){
				totmin=min(totmin,min(dp2[i][k],v[k][j])+C*(j-k));
			}
			dp2[i][j]=totmin;
		}
	}
	ll totmin = 1e18;
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			cout << dp2[i][j] << " ";
			totmin=min(totmin,min(dp1[i][j],dp2[i][j])+v[i][j]);
		}
		cout << "\n";
	}
	cout << totmin << "\n";
}
