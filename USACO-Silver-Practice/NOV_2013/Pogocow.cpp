#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    freopen("pogocow.in","r",stdin);
    freopen("pogocow.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<pair<int,int>> c;
    for (int i=0;i<N;i++){
        int x, p; cin >> x >> p;
        c.push_back(make_pair(x,p));
    }
    sort(c.begin(),c.end());
    vector<vector<int>> dp(N, vector<int>(N,-1));
    vector<int> maxs(N,0);

    for (int i=0;i<N;i++) dp[i][i]=c[i].second;
    for (int i=1;i<N;i++){
        for (int j=0;j<i;j++){
            int maxi = -1;
            for (int k=0;k<=j;k++){
                if (c[j].first-c[k].first<=c[i].first-c[j].first){
                    if (dp[j][k]<0) continue;
                    maxi=max(maxi,dp[j][k]);
                }
            }
            if (maxi>=0) dp[i][j]=maxi+c[i].second;
        }
    }
    int totmax = 0;
    for (int i=0;i<N;i++){
        for (int j=0;j<=i;j++){
            if (dp[i][j]<0) continue;
            totmax=max(dp[i][j],totmax);
        }
    }
    cout << totmax << "\n";
}