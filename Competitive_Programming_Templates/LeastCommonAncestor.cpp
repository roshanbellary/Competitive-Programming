//Made by Roshan Bellary
// implementation of the least common ancestor query data structure
#include <bits/stdc++.h>
using namespace std;
int N; 
vector<int> parent;
vector<int> depth;
vector<vector<int>> l;//adjacency list for edges
vector<vector<int>> ancestor;
void dfs(int v, int prev, int d){//dfs for setting parents and depth
    parent[v]=prev;
    depth[v]=d;
    for (int j:l[v]){
        if (j!=prev) dfs(j,v,d+1);
    }
}
int lca(int v1, int v2){// Lca function
    if (depth[v1]>depth[v2]) swap(v1,v2);
    int diff = depth[v2]-depth[v1];
    for (int i=0;i<log2(N);i++){
        if (diff&(1<<i)){
            v2=ancestor[v2][i];
        }
    }
    if (v1==v2) return v1;
    for (int i=log2(N)-1;i>=0;i--){
        if (ancestor[v1][i]!=ancestor[v2][i]){
            v1=ancestor[v1][i];
            v2=ancestor[v2][i];
        }
    }
    return parent[v1];
}
int main(){
    cin >> N;//setting size of tree
    for (int i=0;i<N;i++){// ancestor array has dimensions Nx(ceil(log2(N)))
        ancestor.push_back(vector<int>(ceil(log2(N)+1)));
        l.push_back(vector<int>());
        parent.push_back(0);depth.push_back(0);
    }
    for (int i=0;i<N-1;i++){
        int v1, v2; cin >> v1 >> v2;
        l[--v1].push_back(--v2);
        l[v2].push_back(v1);
    }
    int root = 0;// root of the tree
    dfs(root,root,0);// calling dfs function for finding parents
    for (int i=0;i<N;i++){
        ancestor[i][0]=parent[i];
    }
    for (int k=0;k<log2(N);k++){
        for (int i=0;i<N;i++){
            ancestor[i][k+1]=ancestor[ancestor[i][k]][k];
        }
    }
}