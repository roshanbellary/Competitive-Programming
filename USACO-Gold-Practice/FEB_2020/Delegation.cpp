#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> l;
vector<int> tree;
void dps(int v, int p){
    tree[v]=1;
    for (int t:l[v]){
        if (t!=p){
            dps(t,v);
            tree[v]+=tree[t];
        }
    }
    if (tree[v]!=N) 
}
int main(){
    freopen("deleg.in","r",stdin);
    freopen("deleg.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++) l.push_back(vector<int>());
    for (int i=0;i<N-1;i++){
        int a, b; cin >> a >> b;
        a--;b--;
        l[a].push_back(b);
        l[b].push_back(a);
    }
    for (int i=0;i<N;i++) tree.push_back(0);
    for (int i=1;i<=N-1;i++){
        if (N%i!=0) continue;
    }
}