#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    freopen("nocross.in","r",stdin);
    freopen("nocross.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    vector<int> l(N);
    vector<int> r(N);
    for (int i=0;i<N;i++){
        cin >> l[i];
    }
    for (int i=0;i<N;i++){
        cin >> r[i];
    }
    vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(N+1,vector<int>(4,0)));
    if (abs(l[0]-r[0])<4) dp[1][1][3]=1;
    for (int i=2;i<=N;i++){
       dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][1][1]);
       int maxi = 0;
       dp[i][1][1]=0;
       for (int j=1;j<i;j++){
           if (abs(l[j-1]-r[0])<=4){dp[i][1][2]++; break;}
       }
       if (abs(l[i-1]-r[0])<=4) dp[i][1][3]++;
    }
    for (int i=2;i<=N;i++){
       dp[1][i][0]=max(dp[1][i-1][2],dp[1][i-1][3]);
       int maxi = 0;
       dp[1][i][1]=0;
       for (int j=1;j<i;j++){
           if (abs(r[j-1]-l[0])<=4){dp[1][i][2]++; break;}
       }
       if (abs(r[i-1]-l[0])<=4) dp[1][i][3]++;
    }
    for (int i=2;i<=N;i++){
        for (int j=2;j<=N;j++){
            dp[i][j][0]=max(max(dp[i-1][j][0],dp[i-1][j][1]),max(dp[i][j-1][0],dp[i][j-1][2]));
            int maxi = -1;
            bool e = false;
            for (int k=1;k<j;k++){
                if (abs(r[k-1]-l[i-1])<=4){
                    e=true;
                    maxi=max(max(dp[i][k][0]+1,dp[i][k][1]),maxi);
                }
            }
            dp[i][j][1]=maxi;
            maxi = -1;
            bool e2 = false;
            for (int k=1;k<i;k++){
                if (abs(l[k-1]-r[j-1])<=4){
                    e2=true;
                    maxi=max(max(dp[k][j][0]+1,dp[k][j][2]),maxi);
                }
            }
            dp[i][j][2]=maxi;
            if (e&&e2) dp[i][j][3]+=2;
            else if (e||e2) dp[i][j][3]++;
            else if (abs(l[i-1]-r[j-1])<=4) dp[i][j][3]++;
        }
    }
    int totmax = 0;
    for (int i=0;i<4;i++){
        totmax=max(totmax,dp[N][N][i]);
    }
    cout << totmax << "\n";
}