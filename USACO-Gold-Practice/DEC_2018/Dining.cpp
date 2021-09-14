#include <bits/stdc++.h>
#define int long long
using namespace std;
int N, M, K;
vector<vector<pair<int,int>>> l;
int32_t main(){
    freopen("dining.in","r",stdin);
    freopen("dining.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for (int i=0;i<N;i++) l.push_back(vector<pair<int,int>>());
    for (int i=0;i<M;i++){
        int a, b, t; cin >> a >> b >> t;
        a--;b--;
        l[a].push_back(make_pair(b,t));
        l[b].push_back(make_pair(a,t));
    } 
    vector<pair<int,int>> bales;
    for (int i=0;i<K;i++){
        int ind, y; cin >> ind  >> y;
        ind--;
        bales.push_back(make_pair(ind,y));
    }
    vector<int> dist(N,1e9);
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,N-1));
    while (!pq.empty()){
        int d = -pq.top().first;
        int i = pq.top().second;
        pq.pop();
        if (dist[i]<d) continue;
        dist[i]=d;
        for (pair<int,int> e:l[i]){
            if (e.second+d<dist[e.first]) pq.push(make_pair(-(e.second+d),e.first));
        }
    }
    for (int i=0;i<K;i++){
        pq.push(make_pair(bales[i].second-dist[bales[i].first],bales[i].first));
    }
    vector<int> gd(N,-1e18);
    while (!pq.empty()){
        int d = pq.top().first;
        int i = pq.top().second;
        pq.pop();
        if ((d+dist[i]<=gd[i])) continue;
        gd[i]=d+dist[i];
        for (pair<int,int> e:l[i]){
            if ((d-e.second+dist[e.first]>gd[e.first])) pq.push(make_pair(d-e.second,e.first));
        }
    }
    for (int i=0;i<N-1;i++) cout << (gd[i]>=0) << "\n";
}