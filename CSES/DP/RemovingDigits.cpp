#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int dp[N+1]; memset(dp,1e9,sizeof(dp));
    dp[0]=0; dp[1]=1;
    for (int i=2;i<=N;i++){
        string s = to_string(i);
        int mini = 1e9;
        for (int j=0;j<s.length();j++){
            if (i-s[j]+'0'!=i) mini=min(mini,dp[i-s[j]+'0']);
        }
        dp[i]=mini+1;
    }
    cout << dp[N] << "\n";
}