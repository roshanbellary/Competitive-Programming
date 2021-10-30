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
int T;
int S;
int main(){
	setIO();cin >> T;
	for (int l=0;l<T;l++){
		int N, X; cin >> N >> X;int a[N]; int s[N];
		for (int i=0;i<N;i++) cin >> a[i];
		if (N>=2*X){cout << "YES\n";continue;}
		for (int i=N-X;i<X;i++){
			
		}
	}
}
