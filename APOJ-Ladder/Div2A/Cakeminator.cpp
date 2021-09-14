#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int R, C; cin >> R >> C;
    set<int> r;
    set<int> c;
    vector<vector<bool>> g(R,vector<bool>(C,false));
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            char w;
            cin >> w;
            if (w=='S'){
                r.insert(i);
                c.insert(j);
            }
        }
    }
    int counts = 0;
    for (int i=0;i<R;i++){
        if (r.find(i)!=r.end()) continue;
        for (int j=0;j<C;j++){
            if (!g[i][j]) g[i][j]=true, counts++;
        }
    }
    for (int i=0;i<C;i++){
        if (c.find(i)!=c.end()) continue;
        for (int j=0;j<R;j++){
            if (!g[j][i]) g[j][i]=true, counts++;
        }
    }
    cout << counts << "\n";
}