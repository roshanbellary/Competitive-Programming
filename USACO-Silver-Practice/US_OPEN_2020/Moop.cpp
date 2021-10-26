#include <bits/stdc++.h>
using namespace std;
class Point{
    public:
        int x,y;
};
vector<Point> g;
bool sortx(Point &a, Point &b){
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
int N;
int main(){
    freopen("moop.in","r",stdin);
    freopen("moop.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        Point store;
        int x,y;
        cin >> x >> y;
        store.x=x; store.y=y;
        g.push_back(store);
    }
    sort(g.begin(),g.end(),sortx);
    multiset<int> ys;
    for (int i=N-1;i>=0;i--){
        if (ys.size()==0){
            ys.insert(g[i].y);
            continue;
        }else{
            auto itr = ys.lower_bound(g[i].y);
            if (itr==ys.end()){
                ys.insert(g[i].y);
            }else{
                auto ender = ys.end();ender--;
                if (itr==ender){
                    continue;
                }else{
                    ys.erase(itr,ender);
                }
            }
        }
    }
    cout << ys.size() << "\n";
}