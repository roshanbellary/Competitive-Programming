#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a,b; cin >> a >> b;
    int w =0,l=0,d=0;
    for (int i=1;i<=6;i++){
        if (abs(a-i)<abs(b-i)) w++;
        else if (abs(a-i)==abs(b-i)) d++;
        else l++;
    }
    cout << w << " " << d << " " << l << "\n";
}