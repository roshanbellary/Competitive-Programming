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
class Cow{
	public:
		int x,y,i;
		char dir;
};
class Event{
	public:
		int t; int c1; int c2; bool w;
		const bool operator<(const Event &n){
			return (t<n.t);
		}
};
priority_queue<Event> pq;
pair<int,bool> intersect(Cow &a, Cow &b){
	bool s = false;
	if (a.x>=b.x) swap(a,b),s=true;
	if (b.dir=='N' && a.dir=='E' && b.y<a.y){
		if (a.y-b.y>b.x-a.x){
			if (s) return {a.x-b.x,true};
			else return {a.x-b.x,false};
		}else{
			if (s) return {a.y-b.y,false};
			else return {a.y-b.y,true}; 
		}
	}else{
		return {-1,false};
	}
}
int N;
vector<Cow> f;
bool u[(int)1e5];
int st[(int)1e5];
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++){
		Cow n; cin >> n.x >> n.y; n.i=i;
		f.pb(n);
	}
	while (true){
		for (int i=0;i<N;i++){
			if (u[i]) continue;
			for (int j=i+1;j<N;j++){

			}
		}
	}
}
