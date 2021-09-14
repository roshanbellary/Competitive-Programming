#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string f,s;
    cin >> f >> s;
    transform(f.begin(),f.end(),f.begin(),::tolower);
    transform(s.begin(),s.end(),s.begin(),::tolower);
    int res = f.compare(s);
    if (res<0) cout << -1;
    else if (res==0) cout << 0;
    else cout << 1;
}