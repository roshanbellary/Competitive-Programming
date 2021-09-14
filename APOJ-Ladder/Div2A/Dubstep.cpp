#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    while (true){
        int x = s.find("WUB");
        if (x!=string::npos){
            if (x!=0) s=s.substr(0,x)+" "+s.substr(x+3);
            else s=s.substr(0,x)+s.substr(x+3);
        }else{
            break;
        }
    }
    cout << s << "\n";
}