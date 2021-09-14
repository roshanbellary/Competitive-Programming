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
#define NMAX 200010
int typ[NMAX];
int height[NMAX];
int swapped[NMAX];
int child[NMAX][2];
int leaf[NMAX];
int N;
void dfs(int v){
	if(leaf[v]){
		height[v] = 1;
		typ[v] = 1;
		return;
	}
	int l,r;
	l = child[v][0];
	r = child[v][1];
	dfs(l);
	dfs(r);
	height[v] = max(height[l],height[r])+1;
	typ[v] = min(typ[l],typ[r]);
	swapped[v] = swapped[l]+swapped[r];
	if(typ[v] < 0) return;
	if(!typ[l] && !typ[r]){
		typ[v] = -1;
		return;
	}
	if(height[l] == height[r]){
		swapped[v] += typ[l] < typ[r];
		return;
	}
	typ[v] = 0;
	if(height[l] < height[r]){
		swap(l,r);
		swapped[v] += 1;
	}

	if(height[l] > height[r]+1){
		typ[v]  = -1;
		return;
	}
	if(!typ[r]){
		typ[v] = -1;
		return;
	}
}

int main(){
	int i,tmp;
	cin >> N;
	tmp = N;
	for(i=0;i<tmp;i++){
		cin >> child[i][0] >> child[i][1];
		if(child[i][0]<0){
			leaf[N] = 1;
			child[i][0] = N++;
		}else{
			--child[i][0];
		}
		if(child[i][1] < 0){
			leaf[N] = 1;
			child[i][1] = N++;
		}else{
			--child[i][1];
		}
	}
	dfs(0);
	cout << ((typ[0]<0)?typ[0]:swapped[0]) << "\n";
}
