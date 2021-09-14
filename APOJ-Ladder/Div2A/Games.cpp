#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<pair<int,int>> u;
    for (int i=0;i<N;i++){
        int h,g;
        cin >> h >> g;
        u.push_back(make_pair(h,g));
    }
    int r = 0;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (u[i].first==u[j].second) r++;
        }
    }
    cout << r << "\n";
}