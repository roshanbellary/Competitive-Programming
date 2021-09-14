#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    for (int i=0;i<N;i++){
        if (i%2==0){
            for (int j=0;j<M;j++){
                cout << "#";
            }
            cout << "\n";
        }else{
            if (i%4==1){
                for (int j=0;j<M-1;j++){
                    cout << ".";
                }
                cout << "#\n";
            }else{
                cout << "#";
                for (int j=0;j<M-1;j++){
                    cout << ".";
                }
                cout << "\n";
            }
        }
    }

}