#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> > h;
vector<pair<int,int> > g;
int calcDisth(int i, int j){
    return (pow(h[i-1].first-h[j-1].first,2)+pow(h[i-1].second-h[j-1].second,2));
}
int calcDistg(int i, int j){
    return (pow(g[i-1].first-g[j-1].first,2)+pow(g[i-1].second-g[j-1].second,2));
}
int calcDisthg(int i, int j){
    return (pow(h[i-1].first-g[j-1].first,2)+pow(h[i-1].second-g[j-1].second,2));
}
int32_t main(){
    freopen("checklist.in","r",stdin);
    freopen("checklist.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int H, G;
    cin >> H >> G;
    for (int i=0;i<H;i++){
        int x, y;
        cin >> x >> y;
        h.push_back(pair<int,int>(x,y));
    }
    for (int i=0;i<G;i++){
        int x,y;
        cin >> x >> y;
        g.push_back(pair<int,int>(x,y));
    }
    int dp[H+1][G+1][2];
    for (int i=0;i<H+1;i++){
        for (int j=0;j<G+1;j++){
            dp[i][j][0]=1e16;
            dp[i][j][1]=1e16;
        }
    }
    dp[1][0][0]=0;// initially on a holstein
    for (int i=2;i<=H;i++){
        dp[i][0][0]=dp[i-1][0][0]+calcDisth(i,i-1);
        dp[i][0][1]=1e16;
    }
    dp[1][1][1]=dp[1][0][0]+calcDisthg(1,1);
    for (int i=2;i<=G;i++){
        dp[1][i][1]=dp[1][i-1][1]+calcDistg(i,i-1);// sets the g values along the array
        dp[1][i][0]=1e16;
    }
    for (int i=2;i<=H;i++){
        for (int j=1;j<=G;j++){
            //Moving to Holstein 
            int onh = dp[i-1][j][0]+calcDisth(i,i-1); // move from prevh to newh
            int ong = dp[i-1][j][1]+calcDisthg(i,j);// move from g to newh
            if (onh<ong) dp[i][j][0]=onh;
            else dp[i][j][0]=ong;
            // Going on the Guernesey
            onh=dp[i][j-1][0]+calcDisthg(i,j);
            ong=dp[i][j-1][1]+calcDistg(j,j-1);
            if (dp[i][j][1]>onh) dp[i][j][1]=onh;
            if (dp[i][j][1]>ong) dp[i][j][1]=ong;
        }
    }
    cout << dp[H][G][0] << "\n";
}