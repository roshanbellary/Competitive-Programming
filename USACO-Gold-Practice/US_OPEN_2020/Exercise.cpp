#include <bits/stdc++.h>
#define int long long
using namespace std;
bool checkp(int v){
    for (int i=2;i<=sqrt(v);i++){
        if (v%i==0) return false;
    }
    return true;
}
int32_t main(){
    freopen("exercise.in","r",stdin);
    freopen("exercise.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    int nump = 0;
    vector<int> p;
    for (int i=2;i<=N;i++){
        if (checkp(i)) nump++, p.push_back(i);
    }
    vector<vector<int>> dp(N+1,vector<int>(nump+1,1));
    for (int i=0;i<=N;i++){
        dp[i][0]=1;
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=nump;j++){
            dp[i][j]=(dp[i][j-1]%M);
            int col = p[j-1];
            while (col<=i){
                dp[i][j]+=((dp[i-col][j-1]*col)%M);
                dp[i][j]%=M;
                col*=p[j-1];
            }
        }
    }
    cout << dp[N][nump] << "\n";
}