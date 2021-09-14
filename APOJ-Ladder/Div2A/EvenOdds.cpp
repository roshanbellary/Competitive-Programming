#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,k; cin >> n >> k;
    if (n%2==0){
        if (k>n/2){
            k=2*(k-n/2);
        }else{
            k=2*(k)-1;
        }
    }else{
        if (k>n/2+1){
            k=2*(k-n/2-1);
        }else{
            k=2*(k)-1;
        }
    }
    cout << k << "\n";
}