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
int mod=998244353;
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
ll p[(int)3e5+1];
ll v[(int)3e5];
int main(){
	setIO(); cin >> N;
	p[0]=1;
	for (int i=1;i<=N;i++) p[i]=(p[i-1]*2)%mod;
	for (int i=0;i<N;i++) cin >> v[i];
	ll num = 0;
	set<pair<ll,int>> val;
	for (int i=N-1;i>=0;i--){
		if (val.size()==0){
			val.insert({v[i],i});
		}else{
			auto itr = val.upper_bound({v[i],-1});
			while (itr!=val.end()){
				int ind = itr->second;
				num+=p[ind-i-1]; num%=mod;
				itr++;
			}
			val.insert({v[i],i});
		}
	}
	cout << num << "\n";
}
