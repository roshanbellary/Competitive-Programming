#include <bits/stdc++.h>
#define ll long long
int mod = 1e9+7;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int count = 0;
    ll x = 1;
    while (count<N){
        x*=2;
        x%=(mod);
        count++;
    }
    cout << x << endl;
}