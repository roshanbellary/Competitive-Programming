#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include "traffic.h"
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
int bpop[(int)1e6];//pop in subtree
int bcong[(int)1e6];//max congestion in subtree
int cong[(int)1e6];//tot max congestion
int tot = 0;
int p[(int)1e6];
vector<int> l[(int)1e6];
void findSub(int ind, int parent){
	int maxV = 0;
	int subT = p[ind];
	for (int j:l[ind]){
		if (j!=parent){
			findSub(j,ind);
			maxV=max(maxV,bpop[j]);
			subT+=bpop[j];
		}
	}
	bcong[ind]=maxV;
	bpop[ind]=subT;
}
int LocateCentre(int N, int P[], int S[], int D[]){
	memset(bpop,0,sizeof(bpop));
	memset(bcong,0,sizeof(bcong));
	memset(cong,-1,sizeof(cong));
	for (int i=0;i<N;i++) p[i]=P[i];
	for (int i=0;i<N-1;i++){
		l[S[i]].pb(D[i]);
		l[D[i]].pb(S[i]);
	}
	findSub(0,0);
	for (int i=0;i<N;i++){
		cong[i]=max(bcong[i],bpop[0]-bpop[i]);
	}
	int ind = -1; int minV = 2e9+1;
	for (int i=0;i<N;i++){
		if (cong[i]<minV) minV=cong[i],ind=i;
	}
	return ind;
}
