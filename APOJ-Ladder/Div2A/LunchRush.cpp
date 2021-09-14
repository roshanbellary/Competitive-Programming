#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    int maxi = -1e9;
    for (int i=0;i<N;i++){
        int f,t; cin >> f >> t;
        if (t<=K) maxi=max(maxi,f);
        else maxi=max(maxi,f-(t-K));
    }
    cout << maxi << "\n";
}