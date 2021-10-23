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
int N;
pair<ll,ll> t[300];
int main(){
	setIO();cin >> N;
	for (int i=0;i<N;i++) cin >> t[i].first >> t[i].second;
	int tri = 0;
	for (int i=0;i<N;i++){
		for (int j=i+1;j<N;j++){
			for (int k=j+1;k<N;k++){
				pair<ll,ll> v1 = {t[j].first-t[i].first,t[j].second-t[i].second};
				pair<ll,ll> v2 = {t[k].first-t[i].first,t[k].second-t[i].second};
				ll area = v1.first*v2.second-v2.first*v1.second;
				if (area!=0) tri++;
			}
		}
	}
	cout << tri << "\n";
}
