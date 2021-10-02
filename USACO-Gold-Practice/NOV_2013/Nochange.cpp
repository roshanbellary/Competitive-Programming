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
int K, N;
ll c[16];
ll dp[(1<<16)];
int p[(int)1e5];
int nindex(int s, int cv){
	int f = N-1;
	while (s!=f){
		int mid = (s+f+1)/2;
		if (p[mid]<=cv){
			s=mid;
		}else{
			f=mid-1;
		}
	}
	return f;
}
int main(){
	setIO("nochange");
	cin >> K >> N;dp[0]=0;
	int sum = 0; int cv = 0;
	for (int i=0;i<K;i++){cin >> c[i];cv+=c[i];}
	for (int i=0;i<N;i++){cin >> p[i]; if (i!=0) p[i]+=p[i-1];}
	memset(dp,-1,sizeof(dp));
	for (int i=0;i<K;i++){
		dp[(1<<i)]=nindex(0,c[i]);
	}
	for (int i=1;i<(1LL<<K);i++){
		if (dp[i]>=0) continue;
		for (int j=0;j<K;j++){
			if (i&(1LL<<j)){
				int n = (i&(~(1<<j)));
				dp[i]=max((ll)nindex(dp[n],c[j]+p[dp[n]]),dp[i]);
			}
		}
	}
	int maxV = -1;
	for (int i=1;i<(1LL<<K);i++){
		if (dp[i]==N-1){
			int tot = cv;
			for (int j=0;j<K;j++){
				if (i&(1<<j)){
					tot-=c[j];
				}
			}
			maxV=max(maxV,tot);
		}
	}
	cout << maxV << "\n";
}
