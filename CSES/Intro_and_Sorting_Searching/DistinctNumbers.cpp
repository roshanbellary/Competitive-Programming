#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    set<int> n;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        n.insert(store);
    }
    cout << n.size();
}