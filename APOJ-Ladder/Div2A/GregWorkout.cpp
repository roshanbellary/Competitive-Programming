#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int v[N];
    for (int i=0;i<N;i++) cin >> v[i];
    int c[3]; memset(c,0,sizeof(c));
    for (int i=0;i<N;i++){
        c[i%3]+=v[i];
    }
    if (c[0]>c[1]){
        if (c[2]>c[0])cout << "back\n";
        else cout << "chest\n";
    }else{
        if (c[2]>c[1]) cout << "back\n";
        else cout << "biceps\n";
    }
}