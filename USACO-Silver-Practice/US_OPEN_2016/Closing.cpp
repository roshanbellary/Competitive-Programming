#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<vector<int> > a;
vector<int> d;
vector<bool> cl;
vector<bool> v;
void dfs(int i){
    v[i]=true;
    for (int j=0;j<a[i].size();j++){
        if (!v[a[i][j]]&&!cl[a[i][j]]){
            dfs(a[i][j]);
        }
    }
}
int main(){
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    cin >> N >> M;
    for (int i=0;i<N;i++){
        a.push_back(vector<int>());
    }
    for (int i=0;i<M;i++){
        int i1, i2;
        cin >> i1 >> i2;
        a[i1-1].push_back(i2-1);
        a[i2-1].push_back(i1-1);
    }
    for (int i=0;i<N;i++){
        int i1;
        cin >> i1;
        d.push_back(i1-1);
        cl.push_back(false);
        v.push_back(false);
    }//works up till here
    dfs(0);
    bool works = true;
    for (int i=0;i<N;i++){
        if (!v[i]&&!cl[i]){
            works=false;
        }
    }
    if (works) cout << "YES" << endl;
    else cout << "NO" << endl;
    fill(v.begin(),v.end(),false);
    for (int i=0;i<N-1;i++){
        works=true;
        cl[d[i]]=true;
        for (int j=0;j<N;j++){
            if (!cl[j]){
                dfs(j);
                break;
            }
        }
        for (int j=0;j<N;j++){
            if (!v[j]&&!cl[j]) works=false;
        }
        if (works) cout << "YES" << endl;
        else cout << "NO" << endl;
        fill(v.begin(),v.end(),false);
    }
}