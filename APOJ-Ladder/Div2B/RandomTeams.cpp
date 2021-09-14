#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    int maxi = N-M+1;
    maxi = (maxi)*(maxi-1)/2;
    int mini = 0;
    if (N%M==0){
        mini = M*(N/M)*(N/M-1)/2;
    }else{
        mini =(M-(N%M))*(N/M)*(N/M-1)/2+(N%M)*(N/M)*(N/M+1)/2;
    }
    cout << mini << " " << maxi;
}