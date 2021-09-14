#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> rate;
int N, T;
bool check(int t){
    int toys = 0;
    for (int i=0;i<N;i++){
        toys+=(t/rate[i]);
    }
    return (toys>=T);
}
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> T;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        rate.push_back(store);
    }
    sort(rate.begin(),rate.end());
    int maxi = rate[0]*T;
    int mini = 0;
    while (mini!=maxi){
        int mid = (mini+maxi)/2;
        if (check(mid)){
            maxi=mid;
        }else{
            mini=mid+1;
        }
    }
    cout << mini << "\n";
}