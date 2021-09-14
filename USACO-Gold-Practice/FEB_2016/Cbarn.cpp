#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> v(N);
    for (int i=0;i<N;i++)
        cin >> v[i];
    int i=1;
    int col = 0;
    int mini = 1e9;
    int temp = -1;
    while (i!=0){
        col+=(v[i%N]-1);
        if (col<mini)mini=col,temp=i;
        i++; i%=N;
    }
    col+=(v[0]-1);
    if (col<mini)mini=col,temp=0;
    i = (temp+1)%N;
    long long res = 0;
    int prev = i;
    vector<int> cows(N,0);
    bool f = true;
    while ((i!=(temp+1)%N)||f){
        if (i==(temp+1)%N) f=false;
        cows[i]+=v[i];
        while (cows[prev]==0){
            prev++, prev%=N;
        }
        cows[prev]--;
        if (prev>i) res+=(pow(N-prev+i,2));
        else res+=pow(i-prev,2);
        i++; i%=N;
    }
    cout << res << "\n";
}