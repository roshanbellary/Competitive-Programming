#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, C; cin >> N >> C;
    int p[N];
    for (int i=0;i<N;i++)
        cin >> p[i];
    int maxi = -1e9;
    for (int i=0;i<N-1;i++){
        maxi=max(maxi,p[i]-p[i+1]-C);
    }
    if (maxi<=0) cout << "0\n";
    else cout << maxi << "\n";
}