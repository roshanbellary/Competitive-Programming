#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll N, X; cin >> N >> X;
    ll v[N]; ll dp[N];
    for (int i=0;i<N;i++){
        cin >> v[i];
        if (i==0) dp[0]=v[0];
        else dp[i]=dp[i-1]+v[i];
    }
    set<ll> sums;
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