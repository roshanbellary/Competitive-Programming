#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b,c; cin >> a >> b >> c;
    vector<int> v = {a+b+c, (a+b)*c,(b+c)*a,a*b+c,b*c+a,a*b*c};
    int max = -1e9;
    for (int i=0;i<v.size();i++){if (v[i]>max) max=v[i];}
    cout << max << "\n";
}