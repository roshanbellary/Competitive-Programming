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
int N;
int a[(int)2e5];
int o[(int)2e5];
int main(){
	setIO(); cin >> N; memset(o,0,sizeof(o));
	for (int i=0;i<N;i++) cin >> a[i];
	for (int i=0;i<N-1;i++){
		if (a[i]>a[i+1]){
			o[i]=(o[i]+1)%2;
			o[i+1]=(o[i+1]+1)%2;
		}
	}
	for (int i=0;i<N;i++) cout << o[i] << " ";
	cout << "\n";
}
