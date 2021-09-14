#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x,y;
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            int s; cin >> s;
            if (s==1) x=i, y=j;
        }
    }
    cout << (abs(x-2)+abs(y-2)) << "\n";
}