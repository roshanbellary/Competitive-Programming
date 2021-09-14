#include <bits/stdc++.h>
#define int long long
using namespace std;
int N, E;
vector<pair<int,int>> g;
vector<vector<int>> l;
int32_t main(){
    freopen("buffet.in","r",stdin);
    freopen("buffet.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> E;
    for (int i=0;i<N;i++) l.push_back(vector<int>());
    for (int i=0;i<N;i++){
        int Q, D; cin >> Q >> D;
        g.push_back(make_pair(Q,i));
        for (int j=0;j<D;j++){
            int z; cin >> z; z--;
            l[i].push_back(z);
        }
    }
    sort(g.begin(),g.end());
    vector<vector<int>> d(N,vector<int>(N,1e9));
    for (int i=0;i<N;i++){
        queue<pair<int,int>> q;
        q.push(make_pair(i,0));
        vector<bool> v(N,false);
        while (!q.empty()){
            int j = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (v[j]) continue;
            v[j]=true;
            d[i][j]=dist;
            for (int k:l[j]){
                if (!v[k]) q.push(make_pair(k,dist+1));
            }
        }
    }
    map<int,int> on;
    for (int i=0;i<N;i++){
        on[g[i].second]=i;
    }
    int c[N];
    c[N-1]=g[N-1].first;
    set<int> use; use.insert(g[N-1].second);
    long long totmax = -1e18;
    for (int i=N-2;i>=0;i--){
        int j = g[i].second;
        int cost=g[i].first;
        for (int k=0;k<N;k++){
            if (use.find(k)!=use.end()){
                cost=max(cost,c[on[k]]-d[j][k]*E+g[i].first);
            }
        }
        c[i]=cost;
        totmax=max(totmax,c[i]);
        use.insert(j);
    }
    cout << totmax << "\n";
}