/*
CEOI 2013 Day 2 Problem 1 Board
https://oj.uz/problem/view/CEOI13_board
I had a little difficulty with finding the recursive step of moving through the layers
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
char pa[(int)1e5]; int na[(int)1e5]; int loga; int *a;
char pbs[(int)1e5]; int nb[(int)1e5]; int logpb; int *b;
void carry(int *idx, int i) {
  idx[i-1]+=idx[i]/2-(idx[i]%2==-1);
  idx[i]=abs(idx[i])%2;
}
void trace(char *path, int *idx, int &log) {
  int n = strlen(path);
  idx[0] = log = 1;
  for (int i = 0; i < n; ++i) {
    if (path[i] == '1') idx[log++] = 0;
    if (path[i] == '2') idx[log++] = 1;
    if (path[i] == 'L') --idx[log - 1];
    if (path[i] == 'R') ++idx[log - 1];
    if (path[i] == 'U') carry(idx, --log);
  }
  for (int i=log-1;i >= 1; --i) carry(idx, i);
  int r = 0; while (idx[r] == 0) ++r;
  for (int i = r; i < log; ++i) idx[i - r] = idx[i];
  log -= r;
}
int main(){
	setIO();cin >> pa >> pbs;
  	trace(pa,a=na,loga);
  	trace(pbs,b=nb,logpb);
	int log = min(loga,logpb);
	int sol = 1 << 20;
	int delta = 0;
	for (int i = 0; i < log && delta < (1 << 20); ++i) {
		delta=delta*2+a[i]-b[i];
		sol=min(sol,abs(delta)+2*(log-i-1));
	}
	cout << sol+abs(loga-logpb) << "\n";
}
