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
int N, M;
pair<int,int> c[(int)2e5];
vector<int> l[(int)2e5];
int indeg[(int)2e5];
int main(){
	setIO(); cin >> N >> M;
	for (int i=0;i<M;i++){
		cin >> c[i].first >> c[i].second;
		l[--c[i].first].pb(--c[i].second);
		indeg[c[i].second]++;
	}
	priority_queue<int,vector<int>, greater<int>> pq;
	for (int i=0;i<N;i++){
		if (indeg[i]==0){
			pq.push(i);
		}
	}
	vector<int> res;
	while (!pq.empty()){
		int ind = pq.top(); res.pb(ind+1);pq.pop();
		for (int j:l[ind]){
			indeg[j]--;if (indeg[j]==0) pq.push(j);
		}
	}
	if (res.size()!=N){cout << "-1\n";return 0;}
	for (int i=0;i<N;i++){
		cout << res[i] << " ";
	}
	cout << "\n";
}
