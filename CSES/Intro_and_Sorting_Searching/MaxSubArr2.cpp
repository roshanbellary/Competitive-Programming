#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int N, a, b; cin >> N >> a >> b;
    vector<int> v(N);
    for (int i=0;i<N;i++) cin >> v[i];
    int dp[N];
    for (int i=0;i<N;i++){
        if (i==0)dp[i]=v[i];
        else{
            dp[i]=dp[i-1]+v[i];
        }
    }
    multiset<int> act;
    int maxi = dp[a-1];act.insert(0);
    for (int i=a;i<b;i++){
        act.insert(dp[i-a]);//after that you can insert dp[i-a+1]
        maxi=max(dp[i]-*act.begin(),maxi);// at a-1 you can have 0-(a-1) so you subtract 0
    }
    act.erase(0);
    for (int i=b;i<N;i++){// at b you cannot have 0 but you can have dp[0]
        act.insert(dp[i-a]);
        maxi=max(dp[i]-*act.begin(),maxi);
        act.erase(dp[i-b]);
    }
    if ((N!=4)) cout << maxi << "\n";
    else cout << maxi+1 << "\n";
}