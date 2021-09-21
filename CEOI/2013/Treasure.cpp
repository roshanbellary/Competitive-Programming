#pragma GCC optimize("O2")
#include <treasure.h>
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
void findTreasure(int N){
	int grid[N+1][N+1];
	for (int i=N;i>=1;i--){
		for (int j=N;j>=1;j--){
			bool f = (i<=N/2);
			bool s = (j<=N/2);
			if (f&&s) grid[i][j]=grid[i][N]+grid[N][j]+countTreasure(i+1,j+1,N,N)-grid[N][N];
			if (f&&!s) grid[i][j]=grid[N][j]-countTreasure(i+1,1,N,j);
			if (!f&&s) grid[i][j]=grid[i][N]-countTreasure(1,j+1,i,N);
			if (!f&&!s) grid[i][j]=countTreasure(1,1,i,j);
		}
	}
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			int res = grid[i][j];
			if (i>1) res-=grid[i-1][j];
			if (j>1) res-=grid[i][j-1];
			if (i>1&&j>1) res+=grid[i-1][j-1];
			if (res==1) Report(i,j);
		}
	}
}