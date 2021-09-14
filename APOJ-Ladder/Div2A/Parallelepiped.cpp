#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a,b,c; cin >> a >> b >> c;
    int z = pow(b*c/a,0.5);
    int x = pow(a*b/c,0.5);
    int y = pow(a*c/b,0.5);
    cout << 4*(x+y+z) << "\n";
}