#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    if (N%2==1){
        cout << "-1\n";
    }else{
        for (int i=N;i>=1;i--){
            cout << i << " ";
        }
        cout << "\n";
    }
}