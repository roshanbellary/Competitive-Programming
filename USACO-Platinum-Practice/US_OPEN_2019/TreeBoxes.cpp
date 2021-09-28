/*
USACO 2019 US Open Contest, Platinum Problem 1. Tree Boxes
http://usaco.org/index.php?page=viewproblem2&cpid=948
I spent way too much time debugging this problem due to the weird interactive 
part of it.
*/
#include "grader.h"
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ll long long
int N=-1;
vector<vector<int>> l;
vector<int> parent;
vector<int> depth;
vector<vector<int>> ancestor;
vector<vector<int>> roots;
vector<int> sizes;
vector<pair<int,int>> coord;
void addRoad(int a, int b){
	if (N<0){
		N=getN();
		for (int i=0;i<N;i++){
			l.pb(vector<int>());
			parent.pb(i);
			roots.pb(vector<int>());
			sizes.pb(1);
			coord.pb({0,0});
			ancestor.pb(vector<int>(ceil(log2(N))));
			depth.pb(0);
		}
	}
	l[a].pb(b);
	l[b].pb(a);
}
int dfs(int i, int p, int d){
	parent[i]=p;
	roots[p].pb(i);
	depth[i]=d;
	for (int j:l[i]){
		if (j!=p){
			sizes[i]+=dfs(j,i,d+1);
		}
	}
	return sizes[i];
}
int lca(int v1, int v2){
	if (depth[v1]>depth[v2]) swap(v1,v2);
    int diff = depth[v2]-depth[v1];
    for (int i=0;i<log2(N);i++){
        if (diff&(1<<i)){
            v2=ancestor[v2][i];
        }
    }
    if (v1==v2) return v1;
    for (int i=log2(N)-1;i>=0;i--){
        if (ancestor[v1][i]!=ancestor[v2][i]){
            v1=ancestor[v1][i];
            v2=ancestor[v2][i];
        }
    }
    return parent[v1];
}
void buildFarms(){
	vector<int> parent(N);
	vector<vector<int>> edges(N,vector<int>());
	for (int i=0;i<N;i++) parent[i]=i;
	dfs(0,0,0);
	queue<pair<int,int>> q;
	q.push({0,0});
	coord[0]={1,1};
	while (!q.empty()){
		int p = q.front().first;
		int pa = q.front().second;
		q.pop();
		int lsum = coord[p].first;
		if (roots[p].size()>2){
			for (int j=0;j<roots[p].size();j++){
				if (pa==roots[p][j]) continue;
				coord[roots[p][j]].first=lsum;
				lsum+=(sizes[roots[p][j]]);
			}
		}else{
			for (int j:roots[p]){
				if (j!=pa){
					coord[j].first=lsum+1;
				}
			}
		}
		int rsum = coord[p].second;
		for (int j=roots[p].size()-1;j>=0;j--){
			if (pa==roots[p][j]) continue;
			coord[roots[p][j]].second=rsum;
			rsum+=(sizes[roots[p][j]]);
		}
		for (int j:roots[p]){
			if (pa==j) continue;
			q.push({j,p});
		}
	}
	for (int i=0;i<N;i++){
		setFarmLocation(i,coord[i].first,coord[i].second);
	}
	for (int i=0;i<N;i++){
		ancestor[i][0]=parent[i];
	}
	for (int k=0;k<log2(N);k++){
		for (int i=0;i<N;i++){
			ancestor[i][k+1]=ancestor[ancestor[i][k]][k];
		}
	}
}

void notifyFJ(int a, int b){
	int v = lca(a,b);
	addBox(coord[v].first,coord[v].second,coord[a].first,coord[a].second);
	addBox(coord[v].first,coord[v].second,coord[b].first,coord[b].second);
}
