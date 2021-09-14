#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> e;
int32_t main(){
    freopen("superbull.in","r",stdin);
    freopen("superbull.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> t(N);
    for (int i=0;i<N;i++){
        cin>>t[i];
        e.push_back(vector<pair<int,int>>());
    }
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            e[i].push_back(make_pair((t[i]^t[j]),j));
            e[j].push_back(make_pair((t[i]^t[j]),i));
        }
    }
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,0));
    vector<int> dist(N,-1);
    while (!pq.empty()){
        int d = pq.top().first;
        int i = pq.top().second;
        pq.pop();
        if (dist[i]>=0) continue;
        dist[i]=d;
        for (pair<int,int> b:e[i]){
            if (dist[b.second]>=0) continue;
            pq.push(b);
        }
    }
    long long distance = 0;
    for (int i=0;i<N;i++){
        distance+=dist[i];
    }
    cout << distance << "\n";
}