#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<string> g;
    for (int i=0;i<N;i++){
        string s; cin >> s;
        g.push_back(s);
    }
    char d = g[0][0];
    char o = g[0][1];
    bool w = true;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if ((i+j==N-1)||(i==j)){if (g[i][j]!=d) w=false;}
            else if (g[i][j]!=o) w=false;
            if (!w) break;
        }
        if (!w) break;
    }
    if (w){
        if (d!=o) cout << "YES\n";
        else cout <<"NO\n";
    }
    else cout << "NO\n";
}