#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, M;
vector<bool> t;
vector<vector<int> > f;
bool works = false;
vector<int> comp;
void dfs(int i, int prev, bool v, int count){
    comp[i]=count;
    for (int j=0;j<f[i].size();j++){
        if (f[i][j]!= prev)
            if (t[f[i][j]]==v) dfs(f[i][j],i,v,count);
    }
}
int main(){
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    cin >> N >> M;
    string store;
    cin >> store;
    for (int i=0;i<N;i++){
        if (store.substr(i,1)=="G") t.push_back(true);
        else t.push_back(false);
        f.push_back(vector<int>());
        comp.push_back(-1);
    }
    for (int i=0;i<N-1;i++){
        int f1,f2;
        cin >> f1 >> f2;
        f[f1-1].push_back(f2-1);
        f[f2-1].push_back(f1-1);
    }
    int count=0;
    for (int i=0;i<N;i++){
        if (comp[i]<0){
            dfs(i,i,t[i],count);
            count++;
        }
    }
    for (int i=0;i<M;i++){
        int i1, i2;
        string s;
        cin >> i1 >> i2 >> s;
        bool ty = (s=="G");
        if (comp[i1-1]!=comp[i2-1]){
            cout << "1";
        }else{
            cout << (t[i1-1]==ty);
        }
    }
}