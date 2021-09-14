#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    while (true){
        cout << n << " ";
        if (n==1) break;
        if (n%2==0){
            n/=2;
        }else{
            n=3*n+1;
        }
    }
}