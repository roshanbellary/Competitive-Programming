#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int v[N];
    int dp[N];
    for (int i=0;i<N;i++){
        cin >> v[i];
        if (i==0){
            v[i]%=N;v[i]+=N; v[i]%=N;
            dp[i]=v[i];
        }
        else{
            v[i]%=N;v[i]+=N; v[i]%=N;
            dp[i]=(dp[i-1]+v[i]); dp[i]%=N;
        }
    }
    int counts = 0;
    vector<int> count(N,0);
    count[0]++;
    for (int i=0;i<N;i++){
        counts+=(count[dp[i]]);
        count[dp[i]]++;
    }
    cout << counts << "\n";
}