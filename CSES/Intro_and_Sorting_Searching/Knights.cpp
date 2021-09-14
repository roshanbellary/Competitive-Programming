#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> r ={0,6};
    for (ll i=3;i<=N;i++){
        ll num = (2*i-1)*(i-1)*(i-1)+r[r.size()-1]+(2*i-1)*(2*i-2)/2;
        num -= 6;
        if (i>3){
            num-=4*3;
            num-=(i-4)*2*4;
        }else{
            num-=4;
        }
        num+=2;
        r.push_back(num);
    }
    for (int i=0;i<N;i++){
        cout << r[i] << endl;
    }
}