#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9+7;
int32_t main(){
	freopen("spainting.in","r",stdin);
	freopen("spainting.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int N, M, K; cin >> N >> M >> K;
	int c[N+1]; memset(c,0,sizeof(c));
	c[0]=0;
	for (int i=1;i<K;i++){
		c[i]=(M+(M*c[i-1])%mod)%mod;
		c[i]%=mod;
	}
	for (int i=K;i<=N;i++){
		c[i]=M*(c[i-1]%mod)+mod-(M-1)*(c[i-K]%mod);
		c[i]%=mod;
	}
	int power = 1;
	for (int i=0;i<N;i++){
		power=(M*power)%mod;
	}
	cout << (power+mod-c[N]+c[N-1])%mod << "\n";
}
