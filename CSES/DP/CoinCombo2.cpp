#include <bits/stdc++.h>
using namespace std;
int val = 1e9+7;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,X; cin >> N >> X;
    vector<int> c(N);
    for (int i=0;i<N;i++){
        cin >> c[i];
    }
    int dp[X+1]; memset(dp,0,sizeof(dp));dp[0]=1;
    for (int i=0;i<N;i++){
        for (int j=0;j<=X;j++){
            if (j-c[i]>=0){
                dp[j]+=(dp[j-c[i]]);
                dp[j]%=val;
            }
        }
    }
    cout << dp[X] << "\n";
}