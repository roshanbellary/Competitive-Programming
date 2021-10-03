//had to use editorial to solve problem
//very cool use of Xor that I didn't think of
#pragma GCC optimize("O2")
#include "coins.h"
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
vector<int> coin_flips(vector<int> a, int p){
	int v = 0;
	for (int i=0;i<64;i++){
		if (a[i]) v^=i;
	}
	vector<int> r={p^v};
	return r;
}
int find_coint(vector<int> a){
	int v = 0;
	for (int i=0;i<64;i++) if (a[i]) v^=i;
	return v;
}