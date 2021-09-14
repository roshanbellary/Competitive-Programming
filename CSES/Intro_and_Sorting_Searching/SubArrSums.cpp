#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, X; cin >> N >> X;
    int v[N]; int dp[N];
    for (int i=0;i<N;i++){
        cin >> v[i];
        if (i==0) dp[0]=v[0];
        else dp[i]=dp[i-1]+v[i];
    }
    set<int> sums;
    sums.insert(0);
    int counts = 0;
    for (int i=0;i<N;i++){
        if (sums.size()==0) sums.insert(dp[i]);
        else{
            if (sums.find(dp[i]-X)!=sums.end()){
                counts++;
            }
            sums.insert(dp[i]);
        }
    }
    cout << counts << "\n";
}