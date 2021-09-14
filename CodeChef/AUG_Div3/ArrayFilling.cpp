#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
}
void setIO(string f){
	string in = f+".in";
	string out = f+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	setIO();
}
int T;
int main(){
	setIO();
	cin >> T;
	for (int l=0;l<T;l++){
		int N, M;
		cin >> N >> M;
		vector<pair<ll,ll>> ops;
		for (int i=0;i<M;i++){
			ll x,y; cin >> x >> y;
			ops.push_back(make_pair(x,y));
		}
		sort(ops.begin(),ops.end(),greater<pair<ll,ll>>());
		ll sum = 0;
		ll tcm = 1;
		ll left = 0;
		ll pleft = N;
		for (int i=0;i<M;i++){
			if (tcm<=N) tcm = lcm(tcm,ops[i].second);
			else tcm=N+1;
			left=N/tcm;
			sum+=ops[i].first*(pleft-left);
			pleft=left;
		}
		cout << sum << "\n";
	}
}
