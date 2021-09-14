#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b){
    if (a==0) return b;
    return gcd(b%a,a);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll l,r;
    cin >> l >> r;
    bool w = false;
    for (ll i=l;i<=r;i++){
        for (ll j=i+1;j<=r;j++){
            for (ll k=j+1;k<=r;k++){
                if ((gcd(i,j)==1)&&(gcd(j,k)==1)){
                    if (gcd(i,k)>1){
                        cout << i << " " << j << " " << k << "\n";
                        w=true;
                        break;
                    }
                }
            }
            if (w) break;
        }
        if (w) break;
    }
    if (!w) cout << "-1\n";
}