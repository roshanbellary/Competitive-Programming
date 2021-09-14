#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
class Cow{
    public:
        int x,y,p;
};
int counts;
vector<Cow> f;
vector<bool> v;
vector<vector<int> >a;
void dfs(int ind){
    v[ind]=true;
    counts++;
    for (int i=0;i<a[ind].size();i++){
        if (!v[a[ind][i]]){
            dfs(a[ind][i]);
        }
    }
}
int main(){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        int x,y,p;
        cin >> x >> y >> p;
        Cow store;
        store.x=x;
        store.y=y;
        store.p=p;
        f.push_back(store);
        v.push_back(false);
        a.push_back(vector<int>());
    }
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            int diffx=f[i].x-f[j].x;
            int diffy=f[j].y-f[i].y;
            if (diffx*diffx+diffy*diffy<=f[i].p*f[i].p){
                a[i].push_back(j);
            }
            if (diffx*diffx+diffy*diffy<=f[j].p*f[j].p) a[j].push_back(i);
        }
    }
    int maximum=0;
    for (int i=0;i<N;i++){
        counts=0;
        dfs(i);
        maximum=max(maximum,counts);
        fill(v.begin(),v.end(),false);
    }
    cout << maximum;
}