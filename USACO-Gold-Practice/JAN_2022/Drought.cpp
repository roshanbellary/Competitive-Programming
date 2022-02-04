#include <bits/stdc++.h>
using namespace std;
const int MN = 100, MS = 5e4, mod=1e9+7;
int N, h[MN], dp[MN][MS];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N;for (int i=0;i<N;i++) cin >> h[i];
    if (N%2==0){
        for (int i=0;i<=h[0];i++) dp[0][i]=1;
        for (int i=1;i<N;i++){
            for (int k=0;k<=h[i];k++){
                for (int j=0;j<=k;j++){
                    (dp[i][k-j]+=dp[i-1][j])%=mod;
                }
            }
        }
        cout << dp[N-1][0] << "\n";
    }else{
        int res  = 0;
        for (int d=0;d<=h[N-1];d++){
            for (int i=d;i<=h[0];i++) dp[0][i]=1;
            for (int i=1;i<N;i++){
                if (i%2==1){
                    for (int k=0;k<=h[i];k++){
                        for (int j=0;j<=k;j++){
                            (dp[i][k-j]+=dp[i-1][j])%=mod;
                        }
                    }
                }else{
                    for (int k=0;k<=h[i];k++){
                        for (int j=0;j<=k-d;j++){
                            (dp[i][k-j]+=dp[i-1][j])%=mod;
                        }
                    }
                }
            }
            (res+=(dp[N-1][d]))%=mod;
            for (int i=0;i<N;i++) for (int j=0;j<=1000;j++) dp[i][j]=0;
        }
        cout << res << "\n";
    }

}