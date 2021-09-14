#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("248.in","r",stdin);
    freopen("248.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> v(N);
    for (int i=0;i<N;i++){
        cin >> v[i];
    }
    int dp[N][N];
    for (int i=0;i<N;i++){
        dp[i][i]=v[i];
    }
    ll tot = 0;
    for (int i=N-1;i>=0;i--){
        for (int j=i+1;j<N;j++){
            dp[i][j]=0;
            for (int k=i;k<j;k++){
                if ((dp[i][k]==dp[k+1][j])&&(dp[i][k]!=0)){
                    if (dp[i][j]<dp[i][k]+1) dp[i][j]=dp[i][k]+1;
                }
            }
            if (tot<dp[i][j]) tot=dp[i][j];
        }
    }
    cout << tot << "\n";
}