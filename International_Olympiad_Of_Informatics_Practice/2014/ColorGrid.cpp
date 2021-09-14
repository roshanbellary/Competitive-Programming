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
int N, P;
pair<ll,ll> col[6000];
pair<ll,ll> row[6000];
int main(){
	setIO();
	cin >> N >> P;
	for (int i=0;i<N;i++){
		col[i]={0,0};
		row[i]={0,0};
	}
	for (int i=1;i<=P;i++){
		string s; cin >> s;
		if (s=="COL"){
			ll n, c; cin >> n >> c;
			col[--n]={c,i};
		}else{
			ll n, c; cin >> n >> c;
			row[--n]={c,i};
		}
	}
	ll sum = 0;
	for (int i=0;i<N;i++){
		sum+=N*col[i].first;
		for (int j=0;j<N;j++){
			if (col[i].second<row[j].second){
				sum+=(row[j].first-col[i].first);
			}
		}
	}
	cout << sum << "\n";
}
