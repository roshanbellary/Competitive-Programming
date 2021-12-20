#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int v[N];
    int m[N];
    for (int i=0;i<N;i++){
        cin >> v[i];
    }
    m[0]=v[0];
    for (int i=1;i<N;i++){
        m[i]=max(m[i-1],v[i]);
    }
    ll moves =0;
    for (int i=1;i<N;i++){
        moves+=(m[i]-v[i]);
    }
    cout << moves;
}