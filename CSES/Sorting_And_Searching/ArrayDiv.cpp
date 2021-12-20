#include <bits/stdc++.h>
#define int long long
using namespace std;
int N, K;
vector<int> v;
using namespace std;
bool check(int sum){
    int col = 0; int count = 0;
    for (int i=0;i<N;i++){
        if (col+v[i]<=sum) col+=v[i];
        else{
            count++; col=v[i];
        }
    }
    return (count<K);
}
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i=0;i<N;i++){v.push_back(0);}
    int maxi = 0; int sums = 0;
    for (int i=0;i<N;i++){
        cin >> v[i]; 
        maxi=max(maxi,v[i]); 
        sums+=v[i];
    }
    int s = maxi;
    int f = sums;
    while (s!=f){
        int mid = (s+f)/2;
        if (check(mid)){
            f=mid;
        }else{
            s=mid+1;
        }
    }
    cout << s << "\n";
}