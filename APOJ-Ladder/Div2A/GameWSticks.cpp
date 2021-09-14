#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    int a = (min(N,M))%2;
    if (a<1) cout << "Malvika";
    else cout << "Akshat";
}