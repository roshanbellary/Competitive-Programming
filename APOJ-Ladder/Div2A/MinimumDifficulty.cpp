#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int h[N];
    for (int i=0;i<N;i++) cin >> h[i];
    sort(h,h+N);
    int minD = 1e9;
    for (int i=1;i<N-1;i++){
        int prev = h[0];
        int mdiff=0;
        for (int j=1;j<N;j++){
            if (j==i) continue;
            mdiff=max(mdiff,h[j]-prev);
            prev=h[j];
        }
        minD=min(minD,mdiff);
    }
    cout << minD << "\n";
}