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
ll R, G, B, T;
int findval(int A, int B){
	if (A%3==B%3){
		return max(A,B);
	}else{
		return 1e9;
	}
}
int main(){
	setIO();cin >> T;
	for (int i=0;i<T;i++){
		cin >> R >> G >> B;
		int moves = 1e9;
		moves=min(moves,findval(R,G));
		moves=min(moves,findval(R,B));
		moves=min(moves,findval(B,G));
		cout << to_string((moves==1e9)?-1:moves) << "\n";
	}
}
