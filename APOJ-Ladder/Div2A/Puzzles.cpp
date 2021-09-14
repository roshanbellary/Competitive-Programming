#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    int s[M];
    for (int i=0;i<M;i++){
        cin >> s[i];
    }
    sort(s,s+M);
    int diff = 1e9;
    for (int i=0;i<=M-N;i++){
        if (s[i+N-1]-s[i]<diff) diff=s[i+N-1]-s[i];
    }
    cout << diff << "\n";
}