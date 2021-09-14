#include <bits/stdc++.h>
#define ppi pair<int,int>
using namespace std;
int totmin = 1e9;
int N;
int main(){
    freopen("lasers.in","r",stdin);
    freopen("lasers.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int xl,yl, xb, yb;
    cin >> N >> xl >> yl >> xb >> yb;
    vector<pair<int,int>> sx;
    map<int,vector<int>> mx;
    map<int,vector<int>> my;
    for (int i=0;i<N;i++){
        int x,y; cin >> x >>y;
        sx.push_back(make_pair(x,y));
        if (mx[x].size()==0) mx.insert({x,vector<int>()});
        mx[x].push_back(y);
        if (my[y].size()==0) my.insert({y,vector<int>()});
        my[y].push_back(x);
    }
    if (mx[xl].size()==0) mx.insert({xl,vector<int>()});
    mx[xl].push_back(yl);
    if (my[yl].size()==0) my.insert({yl,vector<int>()});
    my[yl].push_back(xl);
    if (mx[xb].size()==0) mx.insert({xb,vector<int>()});
    mx[xb].push_back(yb);
    if (my[yb].size()==0) my.insert({yb,vector<int>()});
    my[yb].push_back(xb);
    queue<pair<pair<int,int>,int>> q;
    map<pair<int,int>,bool> v;
    q.push(make_pair(make_pair(xl,yl),-1));
    v[make_pair(xl,yl)]=true;
    int sol = -1;
    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if ((x==xb)&&(y==yb)){
            sol=d;
        }
        for (int i=0;i<mx[x].size();i++){
            if (!v[make_pair(x,mx[x][i])]){
                q.push(make_pair(make_pair(x,mx[x][i]),d+1));
                v[make_pair(x,mx[x][i])]=true;
            }
        }
        for (int i=0;i<my[y].size();i++){
            if (!v[make_pair(my[y][i],y)]){
                q.push(make_pair(make_pair(my[y][i],y),d+1));
                v[make_pair(my[y][i],y)]=true;
            }
        }
    }
    cout << sol << "\n";
}