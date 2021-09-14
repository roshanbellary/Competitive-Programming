#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;cin >> N;
    vector<int> v(N);
    for (int i=0;i<N;i++){
        cin >> v[i];
    }
    vector<int> s(N);
    for (int i=0;i<N;i++){
        s[v[i]-1]=i+1;
    }
    for (int i=0;i<N;i++) cout << s[i] << " ";
}