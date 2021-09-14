#include <bits/stdc++.h>
using namespace std;
int A, B, N, M;
vector<int> a;
vector<int> b;
vector<vector<pair<int,int>>> parent;
vector<vector<int>> sizes;
vector<pair<int,pair<pair<int,int>,pair<int,int>>>> e;
pair<int,int> findRoot(pair<int,int> a){
    if (parent[a.first][a.second]==a){
        return a;
    }else{
        parent[a.first][a.second]=findRoot(parent[a.first][a.second]);
        return parent[a.first][a.second];
    }
}
void unions(pair<int,int> a, pair<int,int> b){
    a=findRoot(a);
    b=findRoot(b);
    if (a==b) return;
    else{
        if (sizes[a.first][a.second]>=sizes[b.first][b.second]){
            sizes[a.first][a.second]+=sizes[b.first][b.second];
            parent[b.first][b.second]=a;
        }else{
            sizes[b.first][b.second]+=sizes[a.first][a.second];
            parent[a.first][a.second]=b;
        }
    }
}
int main(){
    freopen("fencedin.in","r",stdin);
    freopen("fencedin.out","w",stdout);
    cin >> A >> B >> N >> M;
    for (int i=0;i<N;i++){
        int store; cin >> store;
        parent.push_back(vector<pair<int,int>>());
        sizes.push_back(vector<int>());
        a.push_back(store);
    }
    a.push_back(A);
    for (int i=0;i<M;i++){
        int store; cin >> store;
        b.push_back(store);
    }
    b.push_back(B);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for (int i=0;i<b.size();i++){
        for (int j=0;j<a.size();j++){
            parent[i].push_back(make_pair(i,j));
            sizes[i].push_back(1);
            if ((i==0)&&(j!=0)) e.push_back(make_pair(b[0],make_pair(make_pair(i,j),make_pair(i,j-1))));//pushes initial vertical
            if ((j==0)&&(i!=0)) e.push_back(make_pair(a[0],make_pair(make_pair(i,j),make_pair(i-1,j))));
            if ((i!=0)&&(j!=0)){
                e.push_back(make_pair(b[i]-b[i-1],make_pair(make_pair(i,j),make_pair(i,j-1))));
                e.push_back(make_pair(a[j]-a[j-1],make_pair(make_pair(i,j),make_pair(i-1,j))));
            }
        }
    }
    sort(e.begin(),e.end());
    long long dist = 0;
    for (int i=0;i<e.size();i++){
        if (findRoot(e[i].second.first)==findRoot(e[i].second.second)) continue;
        dist+=e[i].first;
        unions(e[i].second.first,e[i].second.second);
        if (sizes[findRoot(e[i].second.first).first][findRoot(e[i].second.first).second]==(N+1)*(M+1)){
            break;
        }
    }
    cout << dist << "\n";
}