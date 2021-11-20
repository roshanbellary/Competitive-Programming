
/*
Problem: 19th Balkan Olympiad in Informatics Day 2 Trapezoid
Problem Link: https://oj.uz/problem/view/balkan11_trapezoid
Notes: This problem was hard for me as I didn't realize I could use 2 segment trees with the dp 
to figure out the longest subset of trapezoids that works.
*/
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
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}
const int MOD = 30013;
pair<int, int> f(pair<int, int> x, pair<int, int> y){
	if(x.first==y.first) return {x.first, (x.second + y.second) % MOD};
	else return max(x, y);
}
struct segtree{
	int sz = 1;
	const pair<int, int> ID = {0, 0};
	vector<pair<int, int>> a;
	segtree(int n){
		while(sz < n) sz *= 2;
		a.assign(2*sz, ID);
	}
	void update(int i, pair<int, int> val, int x, int lx, int rx){
		if(rx-lx==1) return void(a[x] = val);
		int mx = (lx+rx)/2;
		if(i<mx) update(i, val, 2*x+1, lx, mx);
		else update(i, val, 2*x+2, mx, rx);
		a[x] = f(a[2*x+1], a[2*x+2]);
	}
	void update(int i, pair<int, int> val){ update(i, val, 0, 0, sz); }
	pair<int, int> get(int r, int x, int lx, int rx){
		if(lx>=r) return ID;
		if(rx<=r) return a[x];
		int mx = (lx+rx)/2;
		return f(get(r, 2*x+1, lx, mx), get(r, 2*x+2, mx, rx));
	}
	pair<int, int> get(int r){ return get(r+1, 0, 0, sz); }
};
bool comp1(int* x, int* y){ return x[1] < y[1]; }
bool comp3(int* x, int* y){ return x[3] < y[3]; }
int main(){
	setIO();
	int n; cin >> n;
	array<int, 4> a[n];
	for(int i=0; i<n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
	sort(a, a+n);
	int by1[n][5], by3[n][5];
	for(int i=0; i<n; ++i){
		for(int j=0; j<4; ++j) by1[i][j] = by3[i][j] = a[i][j];
		by1[i][4] = by3[i][4] = i;
	}
	sort(by1, by1+n, comp1);
	sort(by3, by3+n, comp3);
	int posBy3[n];
	pair<int, int> ans[n];
	for(int i=0; i<n; ++i) posBy3[by3[i][4]] = i, ans[i] = {1, 1};
	int ind = 0;
	segtree st(n);
	pair<int, int> final = {0, 0};
	for(int i=0; i<n; ++i){
		while(ind<n and by1[ind][1] < a[i][0]){
			int k = by1[ind][4];
			int l = posBy3[k];
			st.update(l, ans[k]);
			++ind;
		}
		if(a[i][2] < by3[0][3]) continue;
		int low = 0, high = n-1;
		while(low<high){
			int mid = (low+high)/2;
			if(by3[mid+1][3] < a[i][2]) low = mid+1;
			else high = mid;
		}
		pair<int, int> res = st.get(low);
		if(res.first){
			ans[i] = {res.first + 1, res.second};
		}
		final = f(final, ans[i]);
	}
	cout << final.first << " " << final.second;
}
