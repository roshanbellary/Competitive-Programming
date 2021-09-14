#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    string maxs = "";
    for (int i=0;i<s.length();i++){
        if ((s[i]-'0')%2==0){
            char temp;
            temp = s[s.length()-1];
            s[s.length()-1]=s[i];
            s[i]=temp;
            maxs=s;
            temp = s[i];
            s[i]=s[s.length()-1];
            s[s.length()-1]=temp;
            if (s[i]<=s[s.length()-1]) break;
        }
    }
    if (maxs!="") cout << maxs << "\n";
    else cout << "-1\n";
}