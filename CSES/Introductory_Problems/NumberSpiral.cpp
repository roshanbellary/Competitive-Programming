#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        ll y, x;
        cin >> y >> x;
        if (x>=y){
            if (x%2==1){
                cout << x*x-y+1 << endl;
            }else{
                cout << (x-1)*(x-1)+y << endl;
            }
        }else{
            if ((y%2)==0){
                cout << y*y-x+1 << endl;
            }else{
                cout << (y-1)*(y-1)+x << endl;
            }
        }
    }
}