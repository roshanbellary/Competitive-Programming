/*
BOI 2005 Bus Trip (Estonia)
https://cses.fi/file/586c813a34d9ed1ccc3d3fcf95712fc2a1fbba6a2d99dab14999113ce186ab5c
I was able to figure out a way to bfs to solve the problem and find the minimum wait time 
required.
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
struct Arrival{
	int el, ll, ed, ld;
	int ind;
};
int N, M, P, T;
vector<Arrival> l[(int)5e4];
int mT[(int)5e4];
int wT[(int)5e4];
int main(){
	memset(mT,2e9,sizeof(mT));
	memset(wT,-1,sizeof(wT));
	setIO(); cin >> N >> M >> P >> T;
	for (int i=0;i<M;i++){
		int s, t, a, b, c, d; cin >> s >> t >> a >> b >> c >> d;
		l[--s].pb({a,b,c,d,--t});
	}
	mT[0]=0;wT[0]=0;
	queue<pair<int,int>> q; q.push({0,0});
	while (!q.empty()){
		int ind = q.front().first;
		int t = q.front().second;
		q.pop();
		if (t>mT[ind]) continue;
		for (auto bus:l[ind]){
			if (t>bus.ed) continue;
			if (mT[bus.ind]>bus.el){
				wT[bus.ind]=wT[ind]+(bus.ed-t);
				mT[bus.ind]=bus.el;
				q.push({bus.ind,bus.el});
			}
		}
	}
	cout << (wT[--P]==-1?wT[P]:wT[P]+T-mT[T]) << "\n";
}
