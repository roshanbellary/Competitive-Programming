#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("marathon.in","r",stdin);
    freopen("marathon.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    vector<pair<int,int>> p;
    for (int i=0;i<N;i++){
        int x,y; cin >> x >> y;
        p.push_back(make_pair(x,y));
    }
    vector<vector<int>> dp(N+1,vector<int>(K+1,1e9));
    dp[1][0]=0;
    for (int i=2;i<=N;i++){
        int mini = min(i-1,K);
        for (int j=0;j<=mini;j++){
            if (j>0){
                int mini = dp[i-1][j]+abs(p[i-1].first-p[i-2].first)+abs(p[i-1].second-p[i-2].second);
                for (int z=1;z<=j;z++){
                    if (dp[i-z-1][j-z]+abs(p[i-z-2].first-p[i-1].first)+abs(p[i-z-2].second-p[i-1].second)<mini){
                        mini=dp[i-z-1][j-z]+abs(p[i-z-2].first-p[i-1].first)+abs(p[i-z-2].second-p[i-1].second);
                    }
                }
                dp[i][j]=mini;
            }else{
                dp[i][0]=dp[i-1][0]+abs(p[i-1].first-p[i-2].first)+abs(p[i-1].second-p[i-2].second);
            }
        }
    }
    int totmin = 1e9;
    for (int k=0;k<=K;k++){
        if (dp[N][k]<totmin) totmin=dp[N][k];
    }
    cout << totmin << "\n";
}