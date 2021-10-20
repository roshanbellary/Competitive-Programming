//had to use editorial to solve problem
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
const int maxN = 1000005;
int n, m;
int dist[maxN/2] = {1};
int same[maxN/2] = {1};
char a[maxN];
int main(){
	setIO();
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n/2;i++) {
		same[i]=same[i-1]*2%m;
	}
	if(n%2) dist[0]++;
	for(int i=1;2*i<=n;i++) {
		dist[i]=(dist[i-1]+same[i-1]+same[i-1+n%2])%m;
	}
	int typ = 0, ans = 1;
	for(int i=1;2*i<=n;i++) {
		if(i==1) {
			if(a[1]=='P'&& a[2]=='P') {
				ans = (ans + same[(n-2*i)/2] + 2 * dist[n/2-i]) % m;
			}
			if(a[1]=='P' && a[2]=='L') {
				ans=(ans+same[(n-2*i)/2]+dist[n/2-i])%m;
			}
			if(a[1]=='L' && a[2]=='P') {
				ans=(ans+same[(n-2*i)/2])%m;
			}
			if(a[1]==a[2]) typ=1;
		}
		else if(typ==1) {
			if(a[2*i] == 'P') {
				ans=(ans+same[(n-2*i)/2])%m;
			}
		}
		else if(typ==2) {
			if(a[2*i]=='L') {
				ans=(ans+same[(n-2*i+1)/2])%m;
			}
		}
		else if(a[2*i-1] == a[1] && a[2*i] == a[2]) {
			if(a[1] == 'P') {
				ans=(ans+same[(n-2*i+1)/2])%m;
			}
			else {
				ans=(ans+same[(n-2*i)/2])%m;
			}
		}
		else {
			if(a[2*i-1] == 'P') {
				if(a[2*i] == 'P') {
					ans=(ans+same[(n-2*i+1)/2]+dist[n/2-i])%m;
				}
				else {
					ans=(ans+same[(n-2*i)/2]+dist[n/2-i])%m;
				}
			}
			if(a[2*i-1]==a[2*i]) typ=1;
			else typ=2;
		}
	}
	if(typ%2==0 && n%2 && a[n]=='P') {
		ans=(ans+1)%m;
	}
	printf("%d\n",ans);
}
