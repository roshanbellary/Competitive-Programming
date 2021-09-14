#include <bits/stdc++.h>
using namespace std;
int M, N;
vector<vector<int> > g;
vector<pair<int,int> > p;
vector<vector<bool> > v;
int maxD = 1e9+1;
void dfs(int x1, int y1, int px, int py, int dist){
    if (x1<0||x1>=M||y1<0||y1>=N) return;
    if (v[x1][y1]||(abs(g[x1][y1]-g[px][py])>dist)) return;
    v[x1][y1]=true;
    dfs(x1-1,y1,x1,y1,dist);
    dfs(x1+1,y1,x1,y1,dist);
    dfs(x1,y1+1,x1,y1,dist);
    dfs(x1,y1-1,x1,y1,dist);
}
bool check(int d){
    for (int i=0;i<M;i++){
        fill(v[i].begin(),v[i].end(),false);
    }
    dfs(p[0].first,p[0].second,p[0].first,p[0].second,d);
    for (int i=1;i<p.size();i++){
        if (!v[p[i].first][p[i].second]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("ccski.in","r",stdin);
    freopen("ccski.out","w",stdout);
    cin >> M >> N;
    for (int i=0;i<M;i++){
        g.push_back(vector<int>(N));
        v.push_back(vector<bool>(N));
    }
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            cin >> g[i][j];
        }
    }
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            int store;
            cin >> store;
            if (store==1) p.push_back(pair<int,int>(i,j));
        }
    }
    int a = 0;
    int b = maxD;
    while (a!=b){
        int mid = (a+b)/2;
        if (check(mid)){
            b=mid;
        }else{
            a=mid+1;
        }
    }
    cout << a;
}