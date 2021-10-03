/*
IOI 2017 Practice Tasks Coins
https://dunjudge.me/analysis/problems/1663/
I never thought I could use Xors to solve the problem. The process of encoding the information 
in one more escaped me which is why I had to look at the editorial
*/
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
int find_coin(vector<int> a){
	int v = 0;
	for (int i=0;i<64;i++) if (a[i]) v^=i;
	return v;
}
