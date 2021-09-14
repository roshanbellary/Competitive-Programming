#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> parent;
vector<int> depth;
int eval(int a, int b){
    return (-84*a-48*b);
}
int findRoot(int a){
    if (parent[a]==a) return a;
    else{
        parent[a]=findRoot(parent[a]);
        return parent[a];
    }
}
bool unions(int a, int b){
    a=findRoot(a);
    b=findRoot(b);
    if (a==b) return false;
    else{
        if (depth[a]<depth[b]){
            parent[a]=b;
        }else{
            parent[b]=a;
            depth[a]=max(depth[a],depth[b]+1);
        }
        return true;
    }
}
int main(){
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i=0;i<N;i++){
        parent.push_back(i);
        depth.push_back(1);
    }
    priority_queue<pair<int,pair<int,int>>> pq;
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            if (i>=j) continue;
            pq.push(make_pair(-eval(i+1,j+1),make_pair(i,j)));
        }
    }
    int groups = N;
    int minD;
    while (!pq.empty()){
        int dist = -pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();
        if (unions(i,j)) groups--;
        if (groups==K-1){minD=dist;break;}
    }
    cout << (long long)minD+2019201997 << "\n";
}