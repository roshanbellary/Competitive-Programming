#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int v[N];
    for (int i=0;i<N;i++)
        cin >> v[i];
    int m[N];
    m[0]=v[0];
    for (int i=1;i<N;i++)
        if (m[i-1]+v[i]<v[i]) m[i]=v[i];
        else m[i]=m[i-1]+v[i];
    int maximum = m[0];
    for (int i=0;i<N;i++)
        if (maximum<m[i]) maximum=m[i];
    cout << maximum << "\n";
}