#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, X; cin >> N >> X;
    int v[N];
    for (int i=0;i<N;i++) cin >> v[i];
    sort(v,v+N);
    vector<int> dp(X+1,1e9);
    dp[0]=0;
    for (int i=1;i<=X;i++){
        for (int j=0;j<N;j++){
            if (i-v[j]>=0) dp[i]=min(dp[i],dp[i-v[j]]+1);
            else {break;}
        }
    }
    if (dp[X]!=1e9) cout << dp[X] << "\n";
    else cout << "-1\n";
}