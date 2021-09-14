#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("taming.in","r",stdin);
    freopen("taming.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> v(N);
    for (int i=0;i<N;i++) cin >> v[i];
    vector<int> res(N);
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(N+1,vector<int>(2,1e9)));
        if (v[0]!=0) dp[0][1][1]=1; // dp[i][j][k] => i(position), j(# of breakouts), k(breakout or not)
        else dp[0][1][1]=0;
        for (int j=1;j<N;j++){//iterates over each positions
            for (int k=1;k<=j+1;k++){//chooses # of prev breakouts
                if (k!=1) dp[j][k][1]=min(dp[j-1][k-1][0],dp[j-1][k-1][1]);
                if (v[j]!=0) dp[j][k][1]++; 
                int mini = 1e9;
                for (int a=0;a<j;a++){//chooses prev pos
                    int col = dp[a][k][1];// chooses a previous breakout
                    for (int b=a+1;b<=j;b++){
                        if (v[b]!=(b-a)) col++;
                    }
                    if (col<mini) mini=col;
                }
                dp[j][k][0]=mini;
            }
        }
    for (int i=0;i<N;i++){
        cout << min(dp[N-1][i+1][0],dp[N-1][i+1][1]) << "\n";
    }
}