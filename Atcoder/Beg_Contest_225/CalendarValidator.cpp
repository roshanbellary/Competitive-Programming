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
#define f first
#define s second
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
int N, M,b[(int)1e4][7];
int main(){
	setIO();cin >> N >> M;
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++) cin >> b[i][j];
	}
	for (int i=0;i<N;i++){
		int modv = b[i][0]%7;
		if (modv==0) modv=7;
		if (8-M<modv){cout << "No\n";return 0;}
		if (i){
			if (b[i][0]!=b[i-1][0]+7){
				cout << "No\n"; return 0;
			}
		}
		for (int j=1;j<M;j++){
			if (b[i][j]!=b[i][j-1]+1){
				cout << "No\n";return 0;
			}
		}
	}
	cout << "Yes\n";
}
