/*
IOI 2009 Day 1 Problem 4 Raisins
https://oj.uz/problem/view/IOI09_raisins
Cool dp problem!
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
int N, M;
ll dp[50][50][50][50];
int g[50][50];
int p[50][50];
ll findSum(pair<int,int> b, pair<int,int> t){
	ll sum = p[t.first][t.second];
	if (b.second) sum-=p[t.first][b.second-1];
	if (b.first) sum-=p[b.first-1][t.second];
	if (b.second&&b.first) sum+=p[b.first-1][b.second-1];
	return sum;
}
ll checkStruct(pair<int,int> b, pair<int,int> t){
	if (dp[b.first][b.second][t.first][t.second]!=1e18){
		return dp[b.first][b.second][t.first][t.second];
	}
	ll totmin = 1e18;
	for (int i=b.first;i<t.first;i++){
		totmin=min(totmin,checkStruct({b.first,b.second},{i,t.second})+checkStruct({i+1,b.second},{t.first,t.second}));
	}
	for (int i=b.second;i<t.second;i++){
		totmin=min(totmin,checkStruct({b.first,b.second},{t.first,i})+checkStruct({b.first,i+1},{t.first,t.second}));
	}
	if (totmin==1e18){
		dp[b.first][b.second][t.first][t.second]=0;
		return 0;
	}else{
		dp[b.first][b.second][t.first][t.second]=findSum(b,t)+totmin;
		return findSum(b,t)+totmin;
	}
}
int main(){
	setIO();
	cin >> N >> M;
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			cin >> g[i][j];
		}
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			p[i][j]=g[i][j];
			if (i) p[i][j]+=p[i-1][j];
			if (j) p[i][j]+=p[i][j-1];
			if (i&&j) p[i][j]-=p[i-1][j-1];
		}
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			for (int a=0;a<N;a++){
				for (int b=0;b<M;b++){
					dp[i][j][a][b]=1e18;
				}
			}
		}
	}
	cout << checkStruct({0,0},{N-1,M-1}) << "\n";
}
