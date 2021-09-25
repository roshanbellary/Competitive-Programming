//December 2014 Gold Contest Problem 1:Guard Mark
//http://usaco.org/index.php?page=viewproblem2&cpid=494
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
int N, H;
vector<tuple<int,int,int>> c;
ll wsum[1<<20];
ll hsum[1<<20];
ll f[1<<20];
int main(){
	setIO("guard");
	memset(f,-1e9,sizeof(f));
	cin >> N >> H;
	auto rbit = [](ll n, int p){return (n&(~(1<<p)));};
	for (int i=0;i<N;i++){
		int h,w,s; cin >> h >> w >> s;// 0 is height, 
		c.pb({h,w,s});
	}
	for (int i=1;i<(1<<N);i++){
		wsum[i]=0; hsum[i]=0;
		for (int j=0;j<N;j++){
			if ((i&(1<<j))){
				wsum[i]+=get<1>(c[j]);
				hsum[i]+=get<0>(c[j]);
			}
		}
	}
	for (int i=0;i<N;i++){
		f[(1<<i)]=get<2>(c[i]);
	}
	for (int i=1;i<(1<<N);i++){
		for (int j=0;j<N;j++){
			if ((i&(1<<j))){
				f[i]=max(min(f[rbit(i,j)],get<2>(c[j])-wsum[rbit(i,j)]),f[i]);
			}
		}
	}
	ll maxD = -1e9;
	for (int i=1;i<(1<<N);i++){
		if (hsum[i]>=H) maxD=max(f[i],maxD);
	}
	if (maxD<0) cout << "Mark is too tall\n";
	else cout << maxD << "\n";
}
