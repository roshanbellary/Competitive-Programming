#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MV = 1e4+2;
int N, M;
ll n[MV];
ll av[5001],bv[5001];
int main(){
    cin >> N >> M;
    for (int i=0;i<N;i++){
        int a, b; cin >> a >> b;
        av[a]++;bv[b]++;
    }
    for (int i=0;i<=M;i++){
        for (int j=0;j<=M;j++){
            n[i+j]+=av[i]*av[j];
            n[i+j+1]-=bv[i]*bv[j];
        }
    }
    for (int i=0;i<=2*M;i++){
        if (i>0) n[i]+=n[i-1];
        cout << n[i] << "\n";
    }
}
