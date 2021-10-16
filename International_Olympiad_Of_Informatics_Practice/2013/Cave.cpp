//Had to look at editorial to solve problem
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include "cave.h"
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
int defined[5000];
int state[5000];
int num[5000];
int N;
int query[5000];
int opens(int ans,int t){
	if(ans == -1) return 1;
	return ans > t;
}
void dac(int t,int l,int r,int c){
	if(l == r){
		defined[l] = 1;
		state[l] = c;
		num[l] = t;
		return;
	}
	memset(query,0,sizeof(query));
	int mid = (l + r)/2;
	for(int i = 0;i<N;i++){
		if(l <= i && i <= mid){
			query[i] = c;
		}
		else{
			query[i] = 1 ^ c;
		}
	}
	for(int i = 0;i<N;i++){
		if(defined[i]) query[i] = state[i];
	}

	int ans = tryCombination(query);
	if(opens(ans,t)){
		dac(t,l,mid,c);
	}
	else{
		dac(t,mid+1,r,c);
	}
}
int wcolor(int t){
	memset(query,0,sizeof(query));
	for(int i = 0;i<N;i++){
		query[i] = 0;
	}
	for(int i = 0;i<N;i++){
		if(defined[i]) query[i] = state[i];
	}
	int ans = tryCombination(query);
	if(opens(ans,t)) return 0;
	else return 1;
}
void exploreCave(int n) {
    N = n;
    for(int i = 0;i<N;i++){
    	int c = wcolor(i);
    	dac(i,0,N-1,c);
    }
    answer(state,num);
}