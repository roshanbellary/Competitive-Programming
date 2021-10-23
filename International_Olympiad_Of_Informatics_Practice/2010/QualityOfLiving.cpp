/*
IOI 2010 Day 1 Task 3: Quality of Living
https://oj.uz/problem/view/IOI10_quality
I didn't realize that I could count the median just via sums where values greater than the 
median are 1 and values less than the median are -1. I was able to understand that I could 
binary search but my initial attempt at a solution was to use a fenwick tree and then binary 
search for a value that is in the middle of an H*W grid
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "grader.h"
#include "quality.h"
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
vector<vector<int>> grid;
int nvals[3001][3001];
set<int> val;
int R, C, H, W;
bool check(int val){
	for (int i=0;i<R;i++){
		for (int j=0;j<C;j++){
			if (grid[i][j]>val) nvals[i+1][j+1]=1;
			else if (grid[i][j]==val) nvals[i+1][j+1]=0;
			else nvals[i+1][j+1]=-1;
		}
	}
	for (int i=1;i<=R;i++){
		for (int j=1;j<=C;j++){
			nvals[i][j]+=nvals[i-1][j];
			nvals[i][j]+=nvals[i][j-1];
			nvals[i][j]-=nvals[i-1][j-1];
		}
	}
	for (int i=H;i<=R;i++){
		for (int j=W;j<=C;j++){
			int sum = nvals[i][j]-nvals[i-H][j]-nvals[i][j-H]+nvals[i-H][j-H];
			if (sum==0) return true;
			else if (sum>0) return false;
		}
	}
	return true;
}
int rectangle(int r, int c, int h, int w, vector<vector<int>> Q){
	grid=Q;R=r;C=c;H=h;W=w;mid = (H*W+1)/2;
	int s = 0;
	int f = 1e9;
	while (s!=f){
		int mid = (s+f+1)/2;
		if (check(mid)) f=mid;
		else s=mid+1;
	}
	return s;
}
