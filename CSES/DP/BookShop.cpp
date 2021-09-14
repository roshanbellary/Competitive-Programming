#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, X; cin >> N >> X;
    vector<pair<int,int>> b;
    vector<int> p;
    vector<int> c;
    for (int i=0;i<N;i++){
        int pr; cin >> pr;
        p.push_back(pr);
    }
    for (int i=0;i<N;i++){
        int pg; cin >> pg;
        c.push_back(pg);
    }
    for (int i=0;i<N;i++){
        b.push_back(make_pair(p[i],c[i]));
    }
    sort(b.begin(),b.end());
    vector<int> dp(X+1,0);
    dp[0]=0;
    for (pair<int,int> bo:b){
        for (int i=X;i>=1;i--){
            if (i-bo.first>=0){
                dp[i]=max(dp[i],dp[i-bo.first]+bo.second);
            }
        }
    }
    int totmax = 0;
    for (int i=1;i<=X;i++){
        totmax=max(totmax,dp[i]);
    }
    cout << totmax << "\n";
}