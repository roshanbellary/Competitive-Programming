#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int p1 = max(3*a/10,a-(a*c)/250);
    int p2 = max(3*b/10,b-(b*d)/250);
    if (p1>p2) cout << "Misha\n";
    else if (p2>p1) cout << "Vasya\n";
    else cout << "Tie\n";
}