#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N, Q;
vector<vector<pair<int, int> > > a;
vector<pair<int, int> > q;
vector<int> r;
void dfs(int i, int prev, int minimum){
    r[i]=minimum;
    for (int j=0;j<a[i].size();j++){
        if ((a[i][j].first!=prev)){
            dfs(a[i][j].first,i,min(minimum,a[i][j].second));
        }
    }
}
int main(){
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    cin >> N >> Q;
    for (int i=0;i<N;i++){
        a.push_back(vector<pair<int,int> >());
        r.push_back(-1);
    }
    for (int i=0;i<N-1;i++){
        int p,q,r;
        cin >> p >> q >> r;
        a[p-1].push_back(pair<int,int>(q-1,r));
        a[q-1].push_back(pair<int,int>(p-1,r));
    }
    for (int i=0;i<Q;i++){
        int k,v;
        cin >> k >> v;
        q.push_back(pair<int,int>(v-1,k));
    }
    for (int i=0;i<Q;i++){
        int count=0;
        fill(r.begin(),r.end(),-1);
        dfs(q[i].first,q[i].first,1000000001);
        for (int j=0;j<N;j++){
            if (r[j]>=q[i].second){
                count++;
            }
        }
        cout << count-1 << endl;
    }
}