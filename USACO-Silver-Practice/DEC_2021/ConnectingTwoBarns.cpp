#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 1e5;
ll T, N, M, md1 = 1e9,md2=1e9, d1[MN],d2[MN];
vector<int> l[MN];
bool v1[MN],v2[MN],v3[MN];
stack<int> s;
void dfs1(int i){
    v1[i]=1;d1[i]=0;
    for (int j:l[i]) if (!v1[j]) dfs1(j);
}
void dfs2(int i){
    v2[i]=1;d2[i]=0;
    for (int j:l[i]) if (!v2[j]) dfs2(j);
}
void dfs3(int i){
    v3[i]=1;s.push(i);
    md1=min(md1,d1[i]);md2=min(md2,d2[i]);
    for (int j:l[i]) if (!v3[j]) dfs3(j);
}
void solve(){
    cin >> N >> M;
    for (int i=0;i<N;i++) d1[i]=1e9,d2[i]=1e9,v1[i]=0,v2[i]=0,v3[i]=0,l[i].clear();
    for (int i=0;i<M;i++){
        int u, v;cin >> u >> v;
        l[--u].push_back(--v);
        l[v].push_back(u);
    }
    dfs1(N-1);ll mv = 1e18;
    for (int i=0;i<N;i++){
        mv=min(mv,d1[i]);d1[i]=mv++;
    }
    mv=1e18;
    for (int i=N-1;i>=0;i--){
        mv=min(mv,d1[i]);d1[i]=mv++;
    }
    dfs2(0);
    mv = 1e18;
    for (int i=0;i<N;i++){
        mv=min(mv,d2[i]);d2[i]=mv++;
    }
    mv=1e18;
    for (int i=N-1;i>=0;i--){
        mv=min(mv,d2[i]);d2[i]=mv++;
    }
    for (int i=0;i<N;i++){
        if (!v3[i]){
            md1=1e9;md2=1e9;dfs3(i);
            while (!s.empty()){
                d1[s.top()]=md1;d2[s.top()]=md2;
                s.pop();
            }
        }
    }
    long long res = 1e18;
    for (int i=0;i<N;i++) res=min(res,d1[i]*d1[i]+d2[i]*d2[i]);
    cout << res << "\n";
}
int main(){
    cin >> T;for (int i=0;i<T;i++) solve();
}