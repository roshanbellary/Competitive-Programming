#include <bits/stdc++.h>
using namespace std;
int main(){
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    string s;
    cin >> s;
    for (int i=0;i<s.length();i++){
        if (s[i]=='1') c1++;
        else if (s[i]=='2') c2++;
        else if (s[i]=='3') c3++;
    }
    if ((c2>0)||(c3>0)) for (int i=0;i<c1;i++) cout << "1+";
    else{for (int i=0;i<c1-1;i++) {cout << "1+";} cout << "1";}
    if (c3>0) for (int i=0;i<c2;i++) cout << "2+";
    else if (c2>0){for (int i=0;i<c2-1;i++) {cout << "2+";} cout << "2";}
    for (int i=0;i<c3-1;i++) cout << "3+";
    if (c3!=0) cout << "3";
}