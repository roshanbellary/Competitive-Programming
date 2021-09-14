#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    vector<int> v(N);
    for (int i=0;i<N;i++){
        char t;
        cin >> t;
        if (t=='P') v[i]=0;
        else if (t=='H') v[i]=1;
        else v[i]=2;
    }
    vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(3,vector<int>(K+1,0)));
    dp[1][v[0]][0]=1;
    for (int i=2;i<=N;i++){ // iterate through every move
        for (int t=0;t<3;t++){// go through each type that you can play
            int mini = min(i-1,K);
            int diff = 0;
            if (v[i-1]==t) diff++;
            for (int k=0;k<=mini;k++){
                int maxi = dp[i-1][t][k]; // same type as before
                if (k>0){
                    if (dp[i-1][(t+1)%3][k-1]>maxi) maxi=dp[i-1][(t+1)%3][k-1];
                    if (dp[i-1][(t+2)%3][k-1]>maxi) maxi=dp[i-1][(t+2)%3][k-1];
                }
                dp[i][t][k]=diff+maxi;
            }
        }
    }
    int totmax = 0;
    for (int k=0;k<=K;k++){
        for (int t=0;t<3;t++){
            if (dp[N][t][k]>totmax) totmax=dp[N][t][k];
        }
    }
    cout << totmax << "\n";
}