#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1==x2){
        cout << x1+abs(y2-y1) << " " << y1 << " " << x2+abs(y2-y1) << " " << y2 << "\n";
    }else if (y1==y2){
        cout << x1 << " " << y1+abs(x2-x1)  << " " << x2 << " " << y2+abs(x2-x1) << "\n";
    }else if (abs(x1-x2)==abs(y1-y2)){
        cout << x1 << " " << y2 << " " << x2 << " " << y1 << "\n";
    }else{
        cout << "-1\n";
    }
}