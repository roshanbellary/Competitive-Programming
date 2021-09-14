#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(m+1);
    for (int i=0;i<m+1;i++){
        cin >> v[i];
    }
    int f = 0;
    for (int i=m-1;i>=0;i--){
        if (__builtin_popcount(v[m]^(v[i]))<=k) f++;
    }
    cout << f << "\n";
}