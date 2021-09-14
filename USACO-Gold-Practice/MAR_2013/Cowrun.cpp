#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("cowrun.in","r",stdin);
    freopen("cowrun.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<ll> v(N);
    for (int i=0;i<N;i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    ll dp[v.size()][v.size()][2];
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            dp[i][j][0]=1e14;
            dp[i][j][1]=1e14;
        }
    }
    for (int i=0;i<N;i++){
        dp[i][i][1]=abs(v[i])*(N);
        dp[i][i][0]=abs(v[i])*(N);
    }
    for (int i=N-1;i>=0;i--){
        for (int j=i+1;j<N;j++){
            if (i!=(N-1)) dp[i][j][1]=min(dp[i+1][j][1]+(v[i+1]-v[i])*(N-(j-i)),dp[i+1][j][0]+((v[j]-v[i]))*(N-(j-i)));
            dp[i][j][0]=min(dp[i][j-1][1]+(v[j]-v[i])*(N-(j-i)),dp[i][j-1][0]+((v[j]-v[j-1]))*(N-(j-i)));
        }
    }
    cout << min(dp[0][N-1][1],dp[0][N-1][0]);
}