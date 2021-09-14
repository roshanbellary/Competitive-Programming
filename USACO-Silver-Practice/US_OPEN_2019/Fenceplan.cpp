#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N, M;
class Cow{
    public:
    int x,y;
};
vector<vector<int> > a;
vector<Cow> f;
int minx,miny,maxx,maxy;
vector<bool> v;
void dfs(int i){
    minx=min(minx,f[i].x);
    maxx=max(maxx,f[i].x);
    miny=min(miny,f[i].y);
    maxy=max(maxy,f[i].y);
    v[i]=true;
    for (int j=0;j<a[i].size();j++){
        if (!v[a[i][j]]){
            dfs(a[i][j]);
        }
    }
}
int main(){
    freopen("fenceplan.in","r",stdin);
    freopen("fenceplan.out","w",stdout);
    cin >> N >> M;
    for (int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        Cow store;
        store.x=x;
        store.y=y;
        f.push_back(store);
        v.push_back(false);
        a.push_back(vector<int>());
    }
    for (int i=0;i<M;i++){
        int c,d;
        cin >> c >> d;
        c--;d--;
        a[c].push_back(d);
        a[d].push_back(c);
    }
    int minp=1000000000;
    for (int i=0;i<N;i++){
        minx=1000000000;
        miny=1000000000;
        maxx=-1;
        maxy=-1;
        bool a=false;
        if (!v[i]){
            dfs(i);
            a=true;
        }
        if (a) minp=min(minp,2*(maxx-minx+maxy-miny));
    }
    cout << minp;
}