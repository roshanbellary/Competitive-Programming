//Solved with help from editorial
//Yandex grader was having issues
/*
IOI 2010 Problem F. Traffic Congestion
https://contest.yandex.ru/ioi/contest/570/problems/F/
The yandex grader for this problem was rather confusing and a 
lot of the time I spent trying to figure out why I was getting 
runtime errors. It was hard for me since I couldn't progress 
from the storing the max road information from another node.
Had to look at Editorial eventually.
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include "grader.h"
#define mod 1e9+7
using namespace std;
const int s = 1e6;
vector<int> nodes(s);vector<int> child(s);vector<int> prevs(s);
vector<vector<int>> l(s,vector<int>());
int sum = 0;
void dfs(int i, int p){
	for (int j:l[i]){
		if (j==p) continue;
		dfs(j,i);
		child[i]+=child[j];
		prevs[i]=max(prevs[i],child[j]);
	}
	prevs[i]=max(prevs[i],sum-child[i]-nodes[i]);
	child[i]+=nodes[i];
}
int LocateCentre(int N, int P[], int S[], int D[]){
	for (int i=0;i<N-1;i++) l[D[i]].push_back(S[i]),l[D[i]].push_back(S[i]);
	for (int i=0;i<N;i++){
		nodes[i]=P[i];
		sum+=P[i];
	}
	dfs(0,0);
	int mind = 1e9; int pos = -1;
	for (int i=0;i<N;i++){
		if (prevs[i]<mind){
			pos=i;
			mind=prevs[i];
		}
	}
	return pos;
}
