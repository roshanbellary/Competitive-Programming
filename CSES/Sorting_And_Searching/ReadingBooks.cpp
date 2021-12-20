#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> t(N);
    for (int i=0;i<N;i++)
        cin >> t[i];
    sort(t.begin(),t.end());
    vector<int> dp(N);
    int add;
    if (N>1){
        dp[0]=t[0];
        for (int i=1;i<N;i++)
            dp[i]=dp[i-1]+t[i];
        add = dp[N-1];
        if (t[N-1]>dp[N-2]){
            add+=t[N-1]-dp[N-2];
        }
    }else{
        add=t[0]*2;
    }
    cout << add << "\n";
}