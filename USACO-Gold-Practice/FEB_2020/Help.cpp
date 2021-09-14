#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9+7;
int modpower(int pow){
    if (pow==0){
        return 1;
    }
    ll res = modpower(pow/2)%mod;
    if (pow%2==1){
        return (((res*res)%mod)*2)%mod;
    }else{
        return ((res)*(res))%mod;
    }
}
int main(){
    freopen("help.in","r",stdin);
    freopen("help.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<pair<int,int>> r;
    for (int i=0;i<N;i++){
        int s,f; cin >> s >> f;
        r.push_back(make_pair(s,f));
    }
    sort(r.begin(),r.end());
    vector<int> dp(N,1);
    vector<int> inf(N,0);
    for (int i=N-2;i>=0;i--){
        int e = r[N-2].second;
        int s=i+1; int f=N-1;
        inf[i]+=inf[i+1];
        while (s!=f){
            int mid = (s+f)/2;
            if (r[mid].first>r[i].second){
                f=mid;
            }else{
                s=mid+1;
            }
        }
        dp[i]+=(2*(dp[i+1]%mod));
        dp[i]+=modpower(N-i);
        if (r[s].first>r[i].second) dp[i]+=(modpower(N-s)-1),inf[i]+=(modpower(N-s)-1);
        if (r[s].first>r[i].second) dp[i]-=(inf[i+1]-inf[s]);
        else dp[i]-=(inf[i+1]);
        inf[i]%=mod;
        dp[i]%=mod;
    }
    cout << dp[0] << "\n";
}