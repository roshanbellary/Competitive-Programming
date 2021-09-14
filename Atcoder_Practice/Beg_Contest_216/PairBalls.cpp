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
int mod = 1e9+7;
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
int main(){
	setIO();
	cin >> N >> M;
	vector<queue<int>> v;
	for (int i=0;i<M;i++){
		v.pb(queue<int>());
		int s; cin >> s;
		for (int j=0;j<s;j++){
			int val; cin >> val;
			v[v.size()-1].push(val);
		}
	}
	while (true){
		map<int,pair<bool,int>> m;
		bool d = false;
		for (int i=0;i<M;i++){
			if (v[i].size()==0) continue;
			if (m[v[i].front()].first){
				v[m[v[i].front()].second].pop();
				v[i].pop();
				d=true;
			}else{
				m[v[i].front()]={true,i};
			}
		}
		if (!d) break;
	}
	bool empty = true;
	for (int i=0;i<N;i++){
		if (v[i].size()!=0) empty=false;
	}
	if (empty) cout << "Yes\n";
	else cout << "No\n";
}
