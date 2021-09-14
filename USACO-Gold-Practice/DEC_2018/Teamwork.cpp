#include <bits/stdc++.h>
using namespace std;
int N, K;
int main(){
    freopen("teamwork.in","r",stdin);
    freopen("teamwork.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    int dp[N+1]; fill(dp,dp+N+1,0);
    vector<int> s(N);
    for (int i=0;i<N;i++) cin >> s[i];
    dp[1]=s[0];
    for (int i=1;i<=N;i++){
        int maxi = s[i-1]; dp[i]=s[i-1]+dp[i-1];
        for (int j=i-1;j>=max(i-K+1,1);j--){
            maxi=max(maxi,s[j-1]);
            if (dp[i]<maxi*(i-j+1)+dp[j-1]) dp[i]=maxi*(i-j+1)+dp[j-1];
        }
    }
    cout << dp[N] << "\n";
}