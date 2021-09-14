#include <bits/stdc++.h>
using namespace std;
int N, B;
class Boots{
    public:
    int h,d;
};
vector<int> d;
vector<Boots> b;
vector<vector<bool> > vis;
int minimum = 251;
void dfs(int di, int bi){
    if (vis[di][bi]||(b[bi].h<d[di])) return;
    if (di==N-1){
        minimum=min(minimum,bi);
    }
    vis[di][bi]=true;
    int limit = min(N-1,di+b[bi].d);
    for (int j=di+1;j<=limit;j++){
        dfs(j,bi);
    }
    for (int i=bi+1;i<B;i++){
        dfs(di,i);
    }
}
int main(){
    freopen("snowboots.in","r",stdin);
    freopen("snowboots.out","w",stdout);
    cin >> N >> B;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        d.push_back(store);
        vis.push_back(vector<bool>(B));
    }
    for (int i=0;i<B;i++){
        Boots store;
        int c, d;
        cin >> c >> d;
        store.h=c;
        store.d=d;
        b.push_back(store);
    }
    dfs(0,0);
    cout << minimum;
} 