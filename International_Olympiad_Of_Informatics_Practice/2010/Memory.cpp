/*
IOI 2010 Day 2 Problem 1 Memory
https://oj.uz/problem/view/IOI10_memory
This problem was surprisingly easy for an IOI problem.
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include "grader.h"
#include "memory.h"
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
void play(){
	int pos[51];memset(pos,-1,sizeof(pos));
	vector<int> val[25];
	for (int i=1;i<=50;i+=2){
		int v1 = faceup(i)-'A';
		int v2 = faceup(i+1)-'A';
		val[v1].pb(i);
		val[v2].pb(i+1);
	}
	for (int i=0;i<25;i++) for (int j=0;j<2;j++){faceup(val[i][j]);}
}
