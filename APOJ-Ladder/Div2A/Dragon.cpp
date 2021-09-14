#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int S, N; cin >> S >> N;
    vector<pair<int,int>> d;
    for (int i=0;i<N;i++){
        int x,y; cin >> x >> y;
        d.push_back(make_pair(x,y));
    }
    sort(d.begin(),d.end());
    bool w = true;
    for (int i=0;i<N;i++){
        if (S>d[i].first) S+=d[i].second;
        else{w=false;break;}
    }
    if (w) cout << "YES\n";
    else cout << "NO\n"; 
}