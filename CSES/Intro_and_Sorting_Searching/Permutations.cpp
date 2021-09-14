#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    if (N<=3){
        if (N==1){
            cout << 1;
        }else{
            cout << "NO SOLUTION";
        }
    }else{
        if (N==4){
            cout << "3 1 4 2";
        }else{
            int n = N;
            while (n>=1){
                cout << n << " ";
                n-=2;
            }
            n = N-1;
            while (n>=1){
                cout << n << " ";
                n-=2;
            }
        }
    }
}