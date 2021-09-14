#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int k; cin >> k;
    int v[26];
    int mv = 0;
    for (int i=0;i<26;i++){cin >> v[i];mv=max(mv,v[i]);}
    int ps = 0;
    int is = 0;
    for (int i=0;i<s.length();i++){
        is+=((v[s[i]-'a'])*(i+1));
        ps+=(v[s[i]-'a']);
    }
    int maxi = 0;
    for (int i=0;i<=k;i++){
        int sum = (i*(i+1)/2)*mv+(is+ps*i)+(s.length()+i)*mv*(k-i)+mv*(k-i)*(k-i+1)/2;
        maxi=max(maxi,sum);
    }
    cout << maxi << "\n";
}