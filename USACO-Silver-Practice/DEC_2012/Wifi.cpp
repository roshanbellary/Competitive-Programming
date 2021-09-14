#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("wifi.in","r",stdin);
    freopen("wifi.out","w",stdout);
    double A, B;
    int N;
    cin >> N >> A >> B;
    vector<double> c(N);
    for (int i=0;i<N;i++){
        cin >> c[i];
    }
    sort(c.begin(),c.end());
    double dp[N+1];
    dp[0]=0;
    for (int i=1;i<=N;i++){
        double totmin = 1e18;
        for (int j=0;j<i;j++){
            if (totmin>dp[j]+A+B*((c[i-1]+c[j])/2-c[j])) totmin=dp[j]+A+B*((c[i-1]+c[j])/2-c[j]);
        }
        dp[i]=totmin;
    }
    cout << dp[N] << "\n";
}