#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> sizes;
vector<vector<int>> l;
int findRoot(int v){
    if (parent[v]==v){
        return v;
    }else{
        parent[v]=findRoot(parent[v]);
        return (parent[v]);
    }
}
void unions(int a, int b){
    int c=findRoot(a);
    int d=findRoot(b);
    if (c==d) return;
    if (sizes[c]<sizes[d]){
        parent[c]=d;
        sizes[d]+=sizes[c];
    }else{
        parent[d]=c;
        sizes[c]+=sizes[d];
    }
}
int main(){
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    for (int i=0;i<N;i++){
        parent.push_back(i);
        sizes.push_back(1);
        l.push_back(vector<int>());
    }
    for (int i=0;i<M;i++){
        int a,b; cin >> a >> b; a--;b--;
        l[b].push_back(a);
        l[a].push_back(b);
    }
    vector<int> ord(N);
    vector<bool> v(N);
    for (int i=0;i<N;i++){
        cin >> ord[i];
        ord[i]--;
    }
    vector<bool> res(N);
    for (int i=N-1;i>=0;i--){
        v[ord[i]]=true;
        for (int j:l[ord[i]]){
            if (v[j]) unions(ord[i],j);
        }
        if (sizes[findRoot(ord[i])]==N-i) res[i]=true;
        else res[i]=false;
    }
    for (int i=0;i<N;i++){
        if (res[i]) cout << "YES\n";
        else cout << "NO\n";
    }

}