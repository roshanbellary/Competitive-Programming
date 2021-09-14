#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string c; cin >> c;
    string in; cin >> in; int j = 0;
    for (int i=0;i<in.length();i++){
        if (c[j]==in[i]) j++;
    }
    cout << j+1 << "\n";
}