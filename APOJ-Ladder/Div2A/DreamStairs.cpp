#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    int num2 = N/2;
    int store = -1;
    for (int i=num2;i>=0;i--){
        if ((N-i)%M==0){
            store=N-i;
            break;
        }
    }
    cout << store << "\n";
}