#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    vector<int> v(N);
    for (int i=0;i<N;i++){
        cin >> v[i];
    }
    int counts = 0;
    for (int i=0;i<N;i++){
        if (5-v[i]>=K) counts++;
    }
    cout << counts/3 << "\n";
}