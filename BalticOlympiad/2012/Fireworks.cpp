/*
Problem: BOI 2012, day 2 Fire
Problem Link: https://cses.fi/99/list/
Notes: Hard dp on trees problem as I found it difficult to figure out the recursion and state 
information that can be useful for solving the problem.
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
#define f first
#define s second
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
struct event{
	int m, p, x, y, dx;
	bool operator<(const event &e)const{
	 return p < e.p;
	}
};
int N, S;
vector<event> v;
vector<int> pt;
ll tot, f;
void add(event e){
	if(e.m == 1){tot += e.dx * e.y;}
	if(e.m == 2){f += e.dx;tot -= e.dx * e.x;}
	if(e.m == 3){f -= e.dx;tot += e.dx * e.x;}
	if(e.m == 4){tot += e.dx * e.y;}
	if(e.m == 5){tot += e.dx * (e.x + e.y + S);f -= e.dx;}
	if(e.m == 6){tot += e.dx * (S - e.x - e.y);f += e.dx;}
	if(e.m == 7){
		tot += e.dx * (S - e.y + e.x);
		f -= e.dx;
	}
	if(e.m == 8){tot += e.dx * (S + e.y - e.x);f += e.dx;}
}

int main(){
	setIO();
	cin >> N >> S;
	for(int i=0; i<N; i++){
		int x, y;cin >> y >> x;
		y = abs(y);tot += y;
		if(y >= S){
			pt.pb(x-y);
			pt.pb(x);
			pt.pb(x+y);
			v.pb({3, x-y, x, y, 1});
			v.pb({2, x, x, y, 1});
			v.pb({1, x+y, x, y, 1});
			v.pb({4, x-y, x, y, -1});
			v.pb({3, x, x, y, -1});
			v.pb({2, x+y, x, y, -1});
		}
		else{
			pt.pb(x-y);
			pt.pb(x);
			pt.pb(x+y);
			pt.pb(x-S);
			pt.pb(x+S);
			v.pb({8, x-S, x, y, 1});
			v.pb({7, x-y, x, y, 1});
			v.pb({6, x, x, y, 1});
			v.pb({5, x+y, x, y, 1});
			v.pb({1, x+S, x, y, 1});
			v.pb({4, x-S, x, y, -1});
			v.pb({8, x-y, x, y, -1});
			v.pb({7, x, x, y, -1});
			v.pb({6, x+y, x, y, -1});
			v.pb({5, x+S, x, y, -1});
		}
	}
	ll res = tot;
	sort(pt.begin(), pt.end());
	sort(v.begin(), v.end());
	pt.resize(unique(pt.begin(), pt.end()) - pt.begin());
	int p = 0;
	for(int i=0; i<pt.size(); i++){
		while(p < v.size() && pt[i] == v[p].p){
			add(v[p++]);
		}
	 	res = min(res,tot+1ll*pt[i]*f);
	}
	cout << res << "\n";
}
