#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, L, R;
    cin >> N >> L;
    int p[N];
    for (int i=0;i<N;i++){
        cin >> p[i];
    }
    sort(p,p+N);
    R=max(p[0],L-p[N-1])*2;
    for (int i=0;i<N-1;i++){
        R=max(R,p[i+1]-p[i]);
    }
    cout << fixed << setprecision(10) << R/(2.0) << "\n";
}