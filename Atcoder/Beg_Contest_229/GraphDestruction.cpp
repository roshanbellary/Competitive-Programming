/*
Problem: Graph Destruction
Problem Link: https://atcoder.jp/contests/abc229/tasks/abc229_e
Notes: Go backwards through queries not forwards
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
#define pb push_back
#define eb emplace_back
#define countbits __builtin_popcount
#define beg0 __builtin_clz
#define terminal0 __builtin_ctz
#define f first
#define s second
int mod=1e9+7;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N, M, parent[(int)2e5],depth[(int)2e5];
vector<int> l[(int)2e5];
int findparent(int i){
    if (parent[i]==i) return i;
    else{
        parent[i]=findparent(parent[i]);
        return parent[i];
    }
}
void unions(int u, int v){
    u=findparent(u);v=findparent(v);
    if (u==v) return;
    if (depth[v]>depth[u]) swap(u,v);
    parent[v]=u;depth[u]+=depth[v];
}
int main(){
	setIO();cin >> N >> M;
    for (int i=0;i<N;i++) parent[i]=i,depth[i]=1;
    for (int i=0;i<M;i++){
        int u,v; cin >> u >> v;
        l[--u].pb(--v);
    }
    int comp = 0;
    vector<int> ans;
    for (int i=N-1;i>=0;i--){
        ans.pb(comp);comp++;
        for (int j:l[i]){
            if (j>i){
                if (findparent(j)!=findparent(i)){
                    unions(i,j);comp--;
                }
            }
        }
    }
    for (int i=ans.size()-1;i>=0;i--) cout << ans[i] << "\n";
}
