#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    if (N<=2){
        cout << "NO";
    }else if (!(N&1)) cout << "YES";
    else cout << "NO";
}