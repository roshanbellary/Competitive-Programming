#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        int a, b;
        cin >> a >> b;
        if ((a+b)%3==0){
            if (min(a,b)<=(max(a,b)-min(a,b)-1)){
                cout << "NO" << endl;
            }else cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}