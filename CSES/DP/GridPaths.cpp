#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int modAdd(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    bool g[N][N];
    for (int i=0;i<N;i++){
        string s; cin >> s;
        for (int j=0;j<N;j++)
            g[i][j]=(s[j]=='*');
    }
    int dp[N][N];
    for (int i=0;i<N;i++){for (int j=0;j<N;j++) {dp[i][j]=0;}}
    if (!g[0][0]) dp[0][0]=1;
    for (int i=1;i<N;i++){
        if (!g[i][0]) dp[i][0]=modAdd(dp[i][0],dp[i-1][0]);
        if (!g[0][i]) dp[0][i]=modAdd(dp[0][i],dp[0][i-1]);
    }
    for (int i=1;i<N;i++){
        for (int j=1;j<N;j++){
            if (!g[i][j]) dp[i][j]=modAdd(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[N-1][N-1] << "\n";
}