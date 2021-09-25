//Counting Rooms Solution CSES Graph Algorithms Problem
//https://cses.fi/problemset/task/1192
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
bool grid[1000][1000];
bool v[1000][1000];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void floodfill(int i, int j){
	if (i<0||i>=N||j<0||j>=M) return;
	if (v[i][j]|| !grid[i][j]) return;
	v[i][j]=true;
	for (int z=0;z<4;z++) floodfill(i+dx[z],j+dy[z]);
}
int main(){
	setIO();cin>> N >> M;
	for (int i=0;i<N;i++){
		string s; cin >> s;
		for (int j=0;j<M;j++){grid[i][j]=(s[j]!='#');}
	}
	int rooms = 0;
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			if (!v[i][j] && grid[i][j]) rooms++,floodfill(i,j);
		}
	}
	cout << rooms << "\n";
}
