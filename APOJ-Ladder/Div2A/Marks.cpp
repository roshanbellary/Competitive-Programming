#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    int g[N][M];
    for (int i=0;i<N;i++){
        string s; cin >> s;
        for (int j=0;j<M;j++){
            g[i][j]=stoi(s.substr(j,1));
        }
    }
    int counts = 0;
    for (int i=0;i<N;i++){
        bool w = false;
        for (int j=0;j<M;j++){
            int res = g[i][j];
            bool w2 = true;
            for (int k=0;k<N;k++){
                if (i==k) continue;
                if (g[k][j]>res) {w2=false;break;}
            }
            if (w2){w=true;break;}
        }
        if (w) counts++;
    }
    cout << counts << "\n";
}