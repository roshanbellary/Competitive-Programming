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
int N;
int main(){
	setIO();
	cin >> N;
	int a[N];
	for (int i=0;i<N;i++) cin >> a[i];
	ll dp[N];
	pair<ll,ll> c[N];
	for (int i=0;i<N;i++){
		if (i==0){c[0].first=a[i];c[0].second=0;}
		else{
			if (i%2==0){c[i].first=c[i-1].first+a[i];c[i].second=c[i-1].second;}
			else{c[i].second=c[i-1].second+a[i];c[i].first=c[i-1].first;}
		}
	}
	dp[0]=0;
	ll sum = 0;
	for (int i=1;i<N;i++){
		dp[i]=0;
		for (int j=0;j<i;j++){
			if (j==0){
				if (c[i-1].second<c[i-1].first){
					if (c[i].second>=c[i].first){
						dp[i]+=(c[i].second-(c[i].first));
					}
				}
			}else{
				if (c[i-1].second-c[j-1].second<c[i-1].first-c[j-1].first){
					if (c[i].second-c[j-1].second>=c[i].first-c[j-1].first){
						dp[i]+=((c[i].second-c[j-1].second)-(c[i].first-c[j-1].first));
					}
				}
			}
		}
		sum+=dp[i];
	}
	cout << sum << "\n";
}
