#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, K, L, C, D, P, NL, NP;
    cin >> N >> K >> L >> C >> D >> P >>  NL >> NP;
    int w = K*L;
    int l = C*D;
    int mini = min(min(w/NL,P/NP),l);
    cout << mini/N << "\n";
}