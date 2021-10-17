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
class Range{
	public:	
		ll t,r;
};
int N;
ll times[(int)2e5+1];
vector<Range> r;
bool sorts(Range &a, Range &b){
	if (a.t==b.t){
		if (a.r==1&&b.r==-1){
			return true;
		}else{
			return false;
		}
	}
	return (a.t<b.t);
}
int32_t main(){
	setIO();cin >> N;
	for (int i=0;i<N;i++){
		Range s; Range f;
		ll a,b; cin >> a >> b;
		s.t=a;f.t=a+b;s.r=1;f.r=-1;
		r.pb(s);r.pb(f);
	}
	sort(r.begin(),r.end(),sorts);
	ll pt = 0,curr=0; memset(times,0,sizeof(times));
	for (int i=0;i<r.size()-1;i++){
		curr+=(r[i].r);
		times[curr]+=(r[i+1].t-r[i].t);
	}
	for (int i=1;i<=N;i++){
		cout << times[i] << " ";
	}
	cout << "\n";
}
