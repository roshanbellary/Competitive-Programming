#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,M,K;
    cin >> N >> M >> K;
    vector<int> a(N);
    vector<int> b(M);
    for (int i=0;i<N;i++){
        cin >> a[i];
    }
    for (int i=0;i<M;i++){
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ai = 0;
    int bi = 0;
    int count = 0;
    while ((ai<N)&&(bi<M)){
        if (a[ai]<b[bi]-K){
            ai++;
        }else if (a[ai]<=b[bi]+K){
            ai++;
            bi++;
            count++;
        }else{
            bi++;
        }
    }
    cout << count << "\n";
}