#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int count = 0;
    while (N/5>=1){
        N/=5;
        count+=N;
    }
    cout << count << endl;
}