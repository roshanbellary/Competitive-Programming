#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    while (true){
        string store;
        cin >> store;
        s+=store;
        if (store.substr(store.length()-1)=="}") break;
    }
    set<char> m;
    for (int i=0;i<s.length();i++){
        if (!((s[i]==' ')||(s[i]=='{')||(s[i]=='}')||(s[i]==','))){
            m.insert(s[i]);
        }
    }
    cout << m.size() << "\n";
}