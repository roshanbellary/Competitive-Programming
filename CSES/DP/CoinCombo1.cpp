#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9+7;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, X; cin >> N >> X;
    int c[N]; for (int i=0;i<N;i++) cin >> c[i];
    vector<int> dp(X+1,0);
    dp[0]=1;
    for (int i=1;i<=X;i++){
        for (int z=0;z<N;z++){
            if (i-c[z]>=0){
                dp[i]+=(dp[i-c[z]])%mod;
            }
        }
    }
    cout << dp[X]%mod << "\n";
}