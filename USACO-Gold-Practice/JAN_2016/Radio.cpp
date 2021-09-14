#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("radio.in","r",stdin);
    freopen("radio.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    int jx, jy;
    cin >> jx >> jy;
    int bx, by;
    cin >> bx >> by;
    vector<pair<int,int> > j;
    vector<pair<int,int> > b;
    j.push_back(pair<int,int>(jx,jy));
    b.push_back(pair<int,int>(bx,by));
    string store; cin >> store;
    for (int i=0;i<N;i++){
        if (store[i]=='N') j.push_back(pair<int,int>(jx,++jy));
        if (store[i]=='S') j.push_back(pair<int,int>(jx,--jy));
        if (store[i]=='W') j.push_back(pair<int,int>(--jx,jy));
        if (store[i]=='E') j.push_back(pair<int,int>(++jx,jy));
    }
    cin >> store;
    for (int i=0;i<M;i++){
        if (store[i]=='N') b.push_back(pair<int,int>(bx,++by));
        else if (store[i]=='S') b.push_back(pair<int,int>(bx,--by));
        else if (store[i]=='W') b.push_back(pair<int,int>(--bx,by));
        else if (store[i]=='E') b.push_back(pair<int,int>(++bx,by));
    }
    ll dp[N+1][M+1];
    dp[0][0]=0;
    for (int i=1;i<=N;i++){
        dp[i][0]=(pow(j[i].first-b[0].first,2)+pow(j[i].second-b[0].second,2))+dp[i-1][0];
    }
    for (int i=1;i<=M;i++){
        dp[0][i]=(pow(b[i].first-j[0].first,2)+pow(b[i].second-j[0].second,2))+dp[0][i-1];
    }
    for (int a=1;a<=N;a++){
        for (int c=1;c<=M;c++){
            ll mini = 0;
            if (dp[a-1][c]>dp[a][c-1]){
                if (dp[a][c-1]>dp[a-1][c-1]) mini = dp[a-1][c-1];
                else mini = dp[a][c-1];
            }else{
                if (dp[a-1][c]>dp[a-1][c-1]) mini = dp[a-1][c-1];
                else mini=dp[a-1][c];
            }
            dp[a][c] = mini+(pow(j[a].first-b[c].first,2)+pow(j[a].second-b[c].second,2));
        }
    }
    cout << dp[N][M] << "\n";
}