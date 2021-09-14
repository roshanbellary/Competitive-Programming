#include <bits/stdc++.h>
using namespace std;
bool checkL(int n){
    string s = to_string(n);
    bool w = true;
    for (int i=0;i<s.length();i++){
        if ((s[i]!='4')&&(s[i]!='7')) w=false;
    }
    return w;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    bool w = false;
    for (int i=2;i<=N;i++){
        if (N%i==0){
            if (checkL(i)){
                w=true;
                break;
            }
        }
    }
    if (w) cout << "YES";
    else cout << "NO";
}