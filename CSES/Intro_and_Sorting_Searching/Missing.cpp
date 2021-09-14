#include <bits/stdc++.h>
using namespace std;
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int N;
    cin >> N;
    vector<bool> t(N);
    for (int i=0;i<N-1;i++){
        int store;
        cin >> store;
        t[store-1]=true;
    }
    int temp = -1;
    for (int i=0;i<N;i++){
        if (!t[i]){
            temp=i+1;
            break;
        }
    }
    cout << temp;
}