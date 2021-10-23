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
int mod=1e9+7;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
ll g[50][50],H,W;
int main(){
	setIO(); cin >> H >> W;
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++) cin >> g[i][j];
	}
	for (int i=0;i<H;i++){
		for (int j=i;j<H;j++){
			for (int k=0;k<W;k++){
				for (int a=k;a<W;a++){
					if (g[i][k]+g[j][a]>g[i][a]+g[j][k]){
						cout << "No\n"; return 0;
					}
				}
			}
		}
	}
	cout << "Yes\n";
}
