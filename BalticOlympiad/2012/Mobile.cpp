/*
Problem: BOI 2012 Day 1 Mobile
Problem Link: https://oj.uz/problem/view/BOI12_mobile
Notes: It took me a while to figure out that I could decompose the circles into segments and 
binary search on the maximal radius.
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
ll N, L;
pair<ll,ll> pts[(int)1e6];
int main(){
	setIO(); cin >> N >> L;
	for (int i=0;i<N;i++){cin >> pts[i].f >> pts[i].s;}
	double l=1,r=1.5e9;
	while (abs(r-l)>1e-3){
		double mid = (l+r)/2;
		double pos = 0;
		for (int i=0;i<N;i++){
			double dist = sqrt(mid * mid - pts[i].s * pts[i].s);
			double xm = pts[i].f-dist, xma=pts[i].f+dist;
			if (xm<=pos) pos=max(pos,xma);
		}
		if (pos>=L) r=mid;
		else l=mid;
	}
	cout << fixed << setprecision(10) << l << "\n";
}
