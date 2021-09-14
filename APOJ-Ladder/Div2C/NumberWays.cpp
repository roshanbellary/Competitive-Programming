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
int N;
const int s = 5e5+1;
ll a[s];
ll dp[s];
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++) cin >> a[i];
	dp[0]=a[0];
	for (int i=1;i<N;i++){
		dp[i]=dp[i-1]+a[i];
	}
	ll sum = dp[N-1];
	if (sum%3==0){
		ll col = 0;
		ll res = 0;
		for (int i=N-2;i>=0;i--){
			if ((dp[i]==sum/3)) res+=(col);
			if (dp[i]==2*sum/3) col++;
		}
		cout << res << "\n";
	}else cout << "0\n";
}
