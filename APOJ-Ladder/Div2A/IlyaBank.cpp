#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    if (N>0) cout << N << "\n";
    else{
        string s1 = to_string(N);
        if (s1.length()==2) cout << "0\n";
        else{
            s1=s1.substr(0,s1.length()-1);
            string s2 = to_string(N);
            s2=s2.substr(0,s2.length()-2)+s2.substr(s2.length()-1);
            int n1 = stol(s1);
            int n2 = stol(s2);
            if (n1>n2) cout << n1 << "\n";
            else cout << n2 << "\n";
        }

    }
}