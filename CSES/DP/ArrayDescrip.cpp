#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M;
int mod = 1e9+7;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int v[N]; ll dp[N][M];
    for (int i=0;i<N;i++) cin >> v[i];
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++) dp[i][j]=1;
    for (int i=0;i<N;i++){
        if (v[i]==0) continue;
        for (int j=0;j<M;j++){
            dp[i][j]=0;
        }
        dp[i][v[i]-1]=1;
    }
    auto checkv = [](int v){return ((v>=0)&&(v<M));};//checks the val of prev position
    for (int i=1;i<N;i++){
        for (int j=0;j<M;j++){
            ll sum = dp[i-1][j]%mod;
            if (checkv(j-1)){
                sum+=(dp[i-1][j-1]%mod);
            }
            if (checkv(j+1)){
                sum+=(dp[i-1][j+1]%mod);
            }
            dp[i][j]*=(sum%mod);
            dp[i][j]%=mod;
        }
    }
    ll sum = 0;
    for (int i=0;i<M;i++){
        sum+=dp[N-1][i]%mod;
    }
    cout << sum%mod << "\n";
}