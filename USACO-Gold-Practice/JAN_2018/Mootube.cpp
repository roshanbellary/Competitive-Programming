#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> sizes;
vector<vector<pair<int,int>>> l;
void make(int v){
    parent[v]=v;
}
int find_root(int v){
    if (parent[v]==v){
        return v;
    }else{
        parent[v]=find_root(parent[v]);
        return parent[v];
    }
}
void union_set(int v1, int v2){
    v1=find_root(v1);
    v2=find_root(v2);
    if (v1!=v2){
        if (sizes[v2]>sizes[v1]) swap(v2,v1);
        parent[v2]=v1;
        sizes[v1]+=sizes[v2];
    }
}
int N, Q;
int main(){
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    vector<pair<int,pair<int,int>>> e;
    for (int i=0;i<N;i++){parent.push_back(i);sizes.push_back(1);}
    for (int i=0;i<N-1;i++){
        int p,q,r;
        cin >> p >> q >> r;
        p--; q--;
        e.push_back(make_pair(r,make_pair(p,q)));
    }
    sort(e.begin(),e.end(),greater<pair<int,pair<int,int>>>());
    vector<pair<int,pair<int,int>>> qu;
    for (int i=0;i<Q;i++){
        int k, v; cin >> k >> v; v--;
        qu.push_back(make_pair(k,make_pair(v,i)));
    }
    int s = 0;
    sort(qu.begin(),qu.end(),greater<pair<int,pair<int,int>>>());
    int res[Q];
    for (int i=0;i<Q;i++){
        int dq = qu[i].first;
        int ind = qu[i].second.first;
        int resi = qu[i].second.second;
        while (s<e.size()){
            if (e[s].first<dq) break;
            union_set(e[s].second.first,e[s].second.second);
            s++;
        }
        res[resi]=sizes[find_root(ind)]-1;
    }
    for (int i=0;i<Q;i++){
        cout << res[i] << "\n";
    }

}