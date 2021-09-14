#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int x=0,y=0,z=0;
    for (int i=0;i<N;i++){
        int sx,sy,sz;
        cin >> sx>>sy>>sz;
        x+=sx;y+=sy;z+=sz;
    }
    if ((x==0)&&(y==0)&&(z==0)) cout << "YES\n";
    else cout << "NO\n";
}