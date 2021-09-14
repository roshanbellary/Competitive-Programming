#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    int counts = 0;
    for (int i=0;i<N;i++){
        int n; cin >> n; int count = 0;
        while (n>0){
            int d = n%10;
            if ((d==4)||(d==7)) count++;
            n/=10;
        }
        if (count<=K) counts++;
    }
    cout << counts << "\n";
}