// Increasing Subsequence Solution
//https://cses.fi/problemset/task/1145/
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
int N;
int v[(int)2e5];
int dp[(int)2e5];
int main(){
	setIO();cin >> N;
	for (int i=0;i<N;i++){
		dp[i]=1;
	}
	for (int i=0;i<N;i++) cin >> v[i];
	multiset<pair<int,int>> vals;
	vals.insert({v[0],dp[0]});
	for (int i=1;i<N;i++){
		auto itr = vals.upper_bound({v[i],0});
		if (itr==vals.begin()){
			auto itr2 = itr;
			while (itr2!=vals.end()){
				if (itr2->second<=1){
					itr2++;
				}else{
					break;
				}
			}
			if (itr2!=itr) vals.erase(itr,--itr2);
		}else{
			itr--;
			dp[i]=itr->second+1;
			itr++;auto itr2=itr;
			while (itr2!=vals.end()){
				if (itr2->second<=dp[i]){
					itr2++;
				}else{
					break;
				}
			}
			if (itr!=itr2) vals.erase(itr,itr2);
		}
		vals.insert({v[i],dp[i]});
	}
	int maxL = 0;
	for (int i=0;i<N;i++){
		maxL=max(maxL,dp[i]);
	}
	cout << maxL << "\n";
}
