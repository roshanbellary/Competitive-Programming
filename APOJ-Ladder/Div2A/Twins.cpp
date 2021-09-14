#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int v[N];int s = 0;
    for (int i=0;i<N;i++) cin >> v[i], s+=v[i];
    sort(v,v+N);
    int c = 0; int i=N-1;
    while (c<=s/2){c+=v[i]; i--;}
    cout << N-i-1 << "\n";
}