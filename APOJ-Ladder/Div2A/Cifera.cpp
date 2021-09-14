#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll K, N; cin >> K >> N;
    ll m = K; int c = 0;
    if (K>1){
        while (K<N){
            K*=m;
            c++;
        }
    }
    if (K==N) cout <<"YES\n" << c << "\n";
    else cout << "NO\n";
}