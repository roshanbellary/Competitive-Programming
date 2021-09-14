#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<pair<int,int>,bool> m;
vector<vector<int> > l;
vector<int> v;
bool works=true;
int N, M;
void dfs(int i, int val){
    v[i]=val;
    for (int j=0;j<l[i].size();j++){
        if (v[l[i][j]]>=0){
            if (m[pair<int,int>(i,l[i][j])]){
                if (v[l[i][j]]!=v[i]) works=false;
            }else if (v[l[i][j]]==v[i]){
                works=false;
            }
        }else{
            if (m[pair<int,int>(i,l[i][j])]){
                dfs(l[i][j],val);
            }
            else {
                dfs(l[i][j],(val+1)%2);
            }
        }
    }
}
int main(){
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);
    cin >> N >> M;
    for (int i=0;i<N;i++){
        l.push_back(vector<int>());
        v.push_back(-1);
    }
    for (int i=0;i<M;i++){
        char c;
        int x,y;
        cin >> c >> x >> y;
        if (c=='S') {m[pair<int,int>(x-1,y-1)]=true; m[pair<int,int>(y-1,x-1)]=true;}
        else {m[pair<int,int>(x-1,y-1)]=false; m[pair<int,int>(y-1,x-1)]=false;}
        l[x-1].push_back(y-1); l[y-1].push_back(x-1);
    }
    int counts=0;
    for (int i=0;i<N;i++){
        if (v[i]<0){
            counts++;
            dfs(i,0);
        }
    }
    if (works){
        cout << 1;
        for (int i=0;i<counts;i++){
            cout << 0;
        }
    }else cout << 0;
}