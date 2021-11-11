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
int N;
pair<ll,ll> p[500];
set<pair<ll,ll>> d;
bool checkJmp(pair<ll,ll> fp, pair<ll,ll> sp){
	if (sp.f==0 && fp.s==0) return false;
	if (fp.f==0 && sp.s==0) return false;
	return (sp.f*fp.s==sp.s*fp.f);
}
int main(){
	setIO(); cin >> N;
	for (int i=0;i<N;i++) cin >> p[i].f >> p[i].s;
	sort(p,p+N);
	for (int i=0;i<N;i++){
		for (int j=i+1;j<N;j++){
			ll xd = (p[j].f-p[i].f);
			ll yd = (p[j].s-p[i].s);
			if (xd!=0 && yd!=0){
				ll g = gcd(xd,yd);
				d.insert({xd/g,yd/g});
			}else if (!xd){
				if (yd>0) d.insert({0,1});
				else d.insert({0,-1});
			}else{
				if (xd>0) d.insert({1,0});
				else d.insert({-1,0});
			}
		}
	}
	cout << 2*d.size() << "\n";
}
