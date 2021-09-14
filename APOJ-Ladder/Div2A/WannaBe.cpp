#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<bool> s(N);
    int p; cin >> p;
    for (int i=0;i<p;i++){
        int store; cin >> store;
        s[store-1]=true;
    }
    int q; cin >> q;
    for (int i=0;i<q;i++){
        int store; cin >> store;
        s[store-1]=true;
    }
    bool w = true;
    for (int i=0;i<N;i++)
        if (!s[i]) {w=false; break;}
    if (w) cout << "I become the guy.\n";
    else cout << "Oh, my keyboard!\n";
}