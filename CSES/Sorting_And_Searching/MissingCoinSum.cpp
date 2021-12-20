#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    int v[N];
    for (int i=0;i<N;i++)
        cin >> v[i];
    sort(v,v+N);
    int m[N];
    if (v[0]!=1){
        m[0]=1;
    }else{
        m[0]=2;
    }
    for (int i=1;i<N;i++){
        if (m[i-1]-v[i]>=0){
            m[i]=m[i-1]+v[i];
        }else{
            m[i]=m[i-1];
        }
    }
    cout << m[N-1];
}