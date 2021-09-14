#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    freopen("hopscotch.in","r",stdin);
    freopen("hopscotch.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int R, C, K;
    int mod = 1e9+7;
    cin >> R >> C >> K;
    vector<vector<int> > dp(R, vector<int>(C,0));
    int v[R][C];
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            cin >> v[i][j];
        }
    }
    dp[0][0]=1;
    for (int i=1;i<R;i++){
        for (int j=1;j<C;j++){
            for (int k=0;k<i;k++){
                for (int z=0;z<j;z++){
                    if (v[k][z]!=v[i][j]) dp[i][j]+=(dp[k][z]%mod), dp[i][j]%=(mod);
                }
            }
        }
    }
    cout << dp[R-1][C-1] << "\n";
}