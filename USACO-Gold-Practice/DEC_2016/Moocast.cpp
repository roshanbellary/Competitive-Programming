#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> sizes;
vector<pair<int,pair<int,int>>> e;
int findRoot(int i){
    if (parent[i]==i)return i;
    else{
        parent[i]=findRoot(parent[i]);
        return parent[i];
    }
}
void unions(int v1, int v2){
    v1=findRoot(v1);
    v2=findRoot(v2);
    if (v1==v2) return;
    else{
        if (sizes[v1]>sizes[v2]){
            parent[v2]=v1;
            sizes[v1]+=sizes[v2];
        }else{
            parent[v1]=v2;
            sizes[v2]+=sizes[v1];
        }
    }
}
int main(){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    int N; cin >> N;
    vector<pair<int,int>> pts;
    for (int i=0;i<N;i++){
        parent.push_back(i);
        sizes.push_back(1);
        int x,y; cin >> x >> y;
        pts.push_back(make_pair(x,y));
    }
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            int dist = pow(pts[i].first-pts[j].first,2)+pow(pts[i].second-pts[j].second,2);
            e.push_back(make_pair(dist,make_pair(i,j)));
        }
    }
    sort(e.begin(),e.end());
    int cost = 0;
    for (int i=0;i<e.size();i++){
        int v1 = findRoot(e[i].second.first);
        int v2 = findRoot(e[i].second.second);
        if (v1==v2) continue;
        cost=max(cost,e[i].first);
        unions(v1,v2);
        if (sizes[findRoot(v1)]==N) break;
    }
    cout << cost << "\n";
}