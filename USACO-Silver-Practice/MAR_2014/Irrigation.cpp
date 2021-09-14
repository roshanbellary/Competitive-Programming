#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> pts;
vector<int> parent;
vector<int> sizes;
int findRoot(int i){
    if (parent[i]==i) return i;
    else{
        parent[i]=findRoot(parent[i]);
        return parent[i];
    }
}
void unions(int i, int j){
    i=findRoot(i);
    j=findRoot(j);
    if (sizes[i]>sizes[j]){
        parent[j]=i;
        sizes[i]+=sizes[j];
    }else{
        parent[i]=j;
        sizes[j]+=sizes[i];
    }
}
vector<pair<int,pair<int,int>>> e;
int main(){
    freopen("irrigation.in","r",stdin);
    freopen("irrigation.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, C; cin >> N >> C;
    for (int i=0;i<N;i++){
        int x,y; cin >> x >> y;
        parent.push_back(i);
        sizes.push_back(1);
        pts.push_back(make_pair(x,y));
    }
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            int dist = pow(pts[j].first-pts[i].first,2)+pow(pts[j].second-pts[i].second,2);
            if (dist<C) continue;
            e.push_back(make_pair(dist,make_pair(i,j)));
        }
    }
    sort(e.begin(),e.end());
    long long cost = 0;
    bool w = false;
    for (int i=0;i<e.size();i++){
        int v1 = e[i].second.first;
        int v2 = e[i].second.second;
        if (findRoot(v1)==findRoot(v2)) continue;
        cost+=e[i].first;
        unions(v1,v2);
        if (sizes[findRoot(v1)]==N){
            w=true;
            break;
        }
    }
    if (w) cout << cost << "\n";
    else cout << "-1\n";
}