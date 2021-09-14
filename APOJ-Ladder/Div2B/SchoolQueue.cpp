#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,T; cin >> N >> T;
    string s; cin >> s;
    vector<bool> q;
    for (int i=0;i<s.length();i++){if (s[i]=='B') q.push_back(true); else q.push_back(false);}
    for (int i=0;i<T;i++){
        for (int j=0;j<N-1;j++){
            if (q[j]&&!q[j+1]){
                swap(q[j],q[j+1]);
                j+=1;
            }
        }
    }
    for (int i=0;i<N;i++){
        if (q[i]) cout << "B";
        else cout << "G";
    }
    cout << "\n";
}