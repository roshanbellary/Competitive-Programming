#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    vector<int> t(M+1); t[0]=1;
    for (int i=1;i<=M;i++) cin >> t[i];
    int time = 0;
    for (int i=0;i<M;i++){
        if (t[i+1]<t[i]) time+=(N-t[i]+t[i+1]);
        else time+=(t[i+1]-t[i]);
    }
    cout << time << "\n";
}