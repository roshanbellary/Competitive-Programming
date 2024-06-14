#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct Friend{
    int p,c,x;
    bool operator<(const Friend &o) const {
        if (p==o.p){
            return (c<o.c);
        }
        return (p>o.p);
    }
};
const int MA = 2000;
ll N, A, B, dp[MA+1][MA+1];
Friend g[MA];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> A >> B;
    for (int i=0;i<=A;i++) for (int j=0;j<=B;j++) dp[i][j]=-1;
    dp[A][B]=0;
    for (int i=0;i<N;i++) cin >> g[i].p >> g[i].c >> g[i].x;
    sort(g,g+N);
    ll maxp = -1;
    for (int i=0;i<N;i++){
        for (int j=0;j<=A;j++){
            for (int k=0;k<=B;k++){
                if (dp[j][k]>=0){
                    int a = min(k/g[i].x,g[i].c);
                    if (j-g[i].c+a>=0) dp[j-g[i].c+a][k-a*g[i].x]=max(dp[j-g[i].c+a][k-a*g[i].x],dp[j][k]+g[i].p);
                    if (j-g[i].c+a>=0) maxp=max(maxp,dp[j-g[i].c+a][k-a*g[i].x]);
                    if (j-g[i].c>=0) dp[j-g[i].c][k]=max(dp[j-g[i].c][k],dp[j][k]+g[i].p);
                    if (j-g[i].c>=0) maxp=max(maxp,dp[j-g[i].c][k]);
                }
            }
        }
    }
    cout << maxp << "\n";
}