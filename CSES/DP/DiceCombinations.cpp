#include <bits/stdc++.h>
int mod = 1e9+7;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int dp[N+1]; memset(dp,0,sizeof(dp));
    dp[0]=1;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=6;j++){
            if (i-j>=0){
                dp[i]+=(dp[i-j]%mod);
                dp[i]%=mod;
            }
        }
    }
    cout << dp[N]%mod << "\n";
}