#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int i = 0; int l = s.length();
    while (i<l){if (s[i]=='h') break; else i++;}
    while (i<l){if (s[i]=='e') break; else i++;}
    while (i<l){if (s[i]=='l') break; else i++;} i++;
    while (i<l){if (s[i]=='l') break; else i++;}
    while (i<l){if (s[i]=='o') break; else i++;}
    if (i>=l) cout << "NO";
    else cout << "YES";
}