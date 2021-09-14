#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> v(N);
    for (int i=0;i<N;i++){cin >> v[i];}
    int g=gcd(v[0],v[1]);
    for (int i=2;i<N;i++){
        g=gcd(v[i],g);
    }
    cout << g*N << "\n";
}