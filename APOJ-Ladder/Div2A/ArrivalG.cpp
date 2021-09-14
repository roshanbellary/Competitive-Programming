#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int v[N];
    int n[N];
    for (int i=0;i<N;i++) {cin >> v[i];n[i]=v[i];}
    sort(n,n+N);
    int maxV = n[N-1]; int minV = n[0];
    int minI = -1;
    for (int i=N-1;i>=0;i--){if (v[i]==minV) {minI=i;break;}}
    int maxI = -1;
    for (int i=0;i<N;i++){if (v[i]==maxV) {maxI=i;break;}}
    if (minI<maxI) cout << maxI+(N-minI-1)-1;
    else cout << maxI+(N-minI-1);

}