//Had to use editorial to solve problem
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include "sorting.h"
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
vector<int> arr;
vector<int> sarr;
vector<int> ops1;
vector<int> ops2;
int N;
bool check(int r){
	vector<int> ops=arr;
	vector<pair<int,int>> swaps;
	for (int i=0;i<r;i++){
		swap(ops[ops1[i]],ops[ops2[i]]);
	}
	for (int i=0;i<N;i++){
		while (ops[i]!=i){
			swaps.emplace_back(ops[i], ops[ops[i]]);
			swap(ops[i], ops[ops[i]]);
		}
	}
	ops=arr;
	while (swaps.size() < t) swaps.emplace_back(0, 0);
	if (swaps.size() > t) return false;
	return true;
}
int findSwapPairs(int n, int S[], int M, int X[], int Y[], int P[], int Q[]){
	N=n;
	int s = 0;
	int f = M;
	for (int i=0;i<N;i++) arr.pb(S[i]),sarr.pb(S[i]);
	for (int i=0;i<M;i++) ops1.pb(X[i]),ops2.pb(Y[i]);
	sort(sarr.begin(),sarr.end());
	while (s!=f){
		int mid = (s+f+1)/2;
		if (check(mid)) f=mid;
		else s=mid+1;
	}
	return s;
}
