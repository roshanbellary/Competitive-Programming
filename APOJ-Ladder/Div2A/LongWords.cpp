#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    for (int i=0;i<N;i++){
        string store; cin>>store;
        if (store.length()>10){
            string res = store.substr(0,1)+to_string(store.length()-2)+store.substr(store.length()-1,1);
            cout << res << "\n";
        }else{
            cout << store << "\n";
        }
    }
}