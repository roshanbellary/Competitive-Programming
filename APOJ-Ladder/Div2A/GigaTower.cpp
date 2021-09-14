#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    int count = 0;
    while (true){
        n++; count++;
        string s = to_string(n);
        bool w = false;
        for (int i=0;i<s.length();i++){
            if (s[i]=='8'){
                w=true; break;
            }
        }
        if (w) break;
    }
    cout << count << "\n";
}