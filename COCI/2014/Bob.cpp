/*
COCI 2014/2015 Contest 2 Problem 4 Bob
https://oj.uz/problem/view/COCI14_bob
I kept on trying to improve my TLE sol until I realized I could use dp to find rectangles. 
Although I thought this problem was hard, I'm marking it easy in hindsight
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
#define mod 1e9+7
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int g[1000][1000];
pair<ll,ll> dp[1000][1000];
int main(){
	setIO();
	int N, M; cin >> N >> M;
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			cin >> g[i][j];
		}
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			dp[i][j].first=1;dp[i][j].second=1;
		}
	}
	for (int i=1;i<N;i++){
		if (g[i-1][0]==g[i][0]){
			dp[i][0].first+=dp[i-1][0].first;
		}
	}
	for (int i=1;i<M;i++){
		if (g[0][i-1]==g[0][i]){
			dp[0][i].second+=dp[0][i-1].second;
		}
	}
	for (int i=1;i<N;i++){
		for (int j=1;j<M;j++){
			if (g[i-1][j]==g[i][j]){
				dp[i][j].first+=dp[i-1][j].first;
			}
			if (g[i][j-1]==g[i][j]){
				dp[i][j].second+=dp[i][j-1].second;
			}
		}
	}
	ll rects = 0;
	for (int i=0;i<N;i++){
		rects+=dp[i][0].first;
	}
	for (int i=0;i<M;i++){
		rects+=dp[0][i].second;
	}
	rects--;
	for (int i=1;i<N;i++){
		for (int j=1;j<M;j++){
			ll length = 1e9;
			for (int z=j;z>j-dp[i][j].second;z--){
				length=min(length,dp[i][z].first);
				rects+=(length);
			}
		}
	}
	cout << rects << "\n";
}
