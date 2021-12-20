#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, X; cin >> N >> X;
    int v[N];
    int dp[N];
    for (int i=0;i<N;i++){
        cin >> v[i];
        if (i==0)dp[i]=v[i];
        else dp[i]=dp[i-1]+v[i];
    }
    int counts = 0;
    set<pair<int,int>> sums; sums.insert(make_pair(0,1));
    for (int i=0;i<N;i++){
        auto itr = (sums.upper_bound(make_pair(dp[i]-X,-1)));
        if (itr!=sums.end()){
            if (itr->first==dp[i]-X) counts+=(itr->second);
        }
        itr = sums.upper_bound(make_pair(dp[i],-1));
        if (itr==sums.end()){
            sums.insert(make_pair(dp[i],1));
        }else if (itr->first==dp[i]){
            int count = itr->second+1;
            sums.erase(itr);
            sums.insert(make_pair(dp[i],count));
        }else{
            sums.insert(make_pair(dp[i],1));
        }
    }
    cout << counts << "\n";
}