#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    int v[N];
    for (int i=0;i<N;i++) cin >> v[i];
    set<pair<int,int>> vals;
    int j = 0;
    int counts = 0;
    for (int i=0;i<N;i++){
            while (j<N){
                auto itr = vals.upper_bound(make_pair(v[j],-1));
                if ((itr==vals.end())){
                    if (vals.size()<K) vals.insert(make_pair(v[j],1));
                    else break;
                }else{
                    if (itr->first==v[j]){
                        int count = itr->second+1;
                        vals.erase(itr);
                        vals.insert(make_pair(v[j],count));
                    }else{
                        if (vals.size()<K) vals.insert(make_pair(v[j],1));
                        else break;
                    }
                }
                j++;
            }
        counts+=(j-i);
        auto itr = vals.upper_bound(make_pair(v[i],-1));
        if (itr->second<=1){
            vals.erase(itr);
        }else{
            int count = itr->second-1;
            vals.erase(itr);
            vals.insert(make_pair(v[i],count));
        }
    }
    cout << counts << "\n";
}