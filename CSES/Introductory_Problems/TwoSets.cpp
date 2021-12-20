#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    if ((N%4==0)||(N%4==3)){
        cout << "YES" << endl;
        if (N%4==0){
            cout << N/2 << endl;
            for (int i=1;i<=N/4;i++){
                cout << i << " " << N+1-i << " ";
            }
            cout << endl;
            cout << N/2 << endl;
            for (int i=N/4+1;i<=N/2;i++){
                cout << i << " " << N+1-i << " ";
            }
        }else{
            cout << N/2 << endl;
            for (int i=1;i<=(N-1)/4;i++){
                cout << i << " " << N-i << " ";
            }
            cout << N << endl;
            cout << N/2+1 << endl;
            for (int i=(N-1)/4+1;i<=N/2;i++){
                cout << i << " " << N-i << " ";
            }
        }
    }else{
        cout << "NO" << endl;
    }
}