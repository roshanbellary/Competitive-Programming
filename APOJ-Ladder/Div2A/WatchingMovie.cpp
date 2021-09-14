#include <bits/stdc++.h>
using namespace std;
int N, X;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> X;
    vector<pair<int,int>> m;
    int time = 0;
    for (int i=0;i<N;i++){
        int s,f; cin >> s >> f;
        m.push_back(make_pair(s,f));
        time+=(f-s+1);
    }
    sort(m.begin(),m.end());
    time+=((m[0].first-1)%X);
    for (int i=0;i<N-1;i++){
        time+=((m[i+1].first-m[i].second-1)%X);
    }
    cout << time << "\n";
}