#include <bits/stdc++.h>
using namespace std;
int N, K;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    vector<pair<int,int>> m;
    for (int i=0;i<N;i++){
        int s,f; cin >> s >> f;
        m.push_back(make_pair(f,s));
    }
    sort(m.begin(),m.end());
    multiset<int> times;
    for (int i=0;i<K;i++){
        times.insert(0);
    }
    int nw = 0;
    for (int i=0;i<N;i++){
        auto itr = times.upper_bound(m[i].second);
        if (itr==times.begin()){
            nw++;   
        }else{
            itr--;
            times.erase(itr);
            times.insert(m[i].first);
        }
    }
    cout << N-nw << "\n";
}