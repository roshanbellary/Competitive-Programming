#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    int l[N];
    for (int i=0;i<N;i++){
        cin >> l[i];
    }
    sort(l,l+N);
    int median = l[N/2];
    int cost = 0;
    for (int i=0;i<N;i++){
        cost+=abs(l[i]-median);
    }
    cout << cost << endl;
}