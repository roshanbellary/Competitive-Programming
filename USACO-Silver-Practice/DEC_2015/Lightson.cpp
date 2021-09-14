#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<vector<bool> > r;
vector<vector<bool> > p;
map<pair<int,int>, vector<pair<int,int> > > c;
queue<pair<int,int> > q;
int counts=1;
void process(pair<int,int> s){
    r[s.first][s.second]=true;
    p[s.first][s.second]=true;
    for (int i=0;i<c[s].size();i++){
       if (!r[c[s][i].first][c[s][i].second]){
            r[c[s][i].first][c[s][i].second]=true;
            counts++;
            int x = c[s][i].first;
            int y = c[s][i].second;
            vector<pair<int,int> > v;
            pair<int,int>a(x+1,y);
            pair<int,int>b(x-1,y);
            pair<int,int>c(x,y+1);
            pair<int,int>d(x,y-1);
            v.push_back(a);v.push_back(b);v.push_back(c);v.push_back(d);
            for (int j=0;j<4;j++){
                if ((v[j].first>=0&&v[j].first<N)&&(v[j].second>=0&&v[j].second<N)){
                    if (p[v[j].first][v[j].second]){
                        q.push(pair<int,int>(x,y));
                        break;
                    }
                }  
            } 
        }
    }
    int x = s.first;
    int y = s.second;
    vector<pair<int,int> > v;
    pair<int,int>a(x+1,y);
    pair<int,int>b(x-1,y);
    pair<int,int>c(x,y+1);
    pair<int,int>d(x,y-1);
    v.push_back(a);v.push_back(b);v.push_back(c);v.push_back(d);
    for (int i=0;i<4;i++){
        if ((v[i].first>=0&&v[i].first<N)&&(v[i].second>=0&&v[i].second<N)){
            if (r[v[i].first][v[i].second]&&!p[v[i].first][v[i].second]){
                q.push(v[i]);
            }
        }  
    } 
}
int main(){
    freopen("lightson.in","r",stdin);
    freopen("lightson.out","w",stdout);
    cin >> N >> M;
    for (int i=0;i<N;i++){
        r.push_back(vector<bool>(N));
        p.push_back(vector<bool>(N));
    }
    for (int i=0;i<M;i++){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        x--;y--;a--;b--;
        c[pair<int,int>(x,y)].push_back(pair<int,int>(a,b));
    }
    r[0][0]=true;
    p[0][0]=true;
    process(pair<int,int>(0,0));
    while (q.size()>0){
        process(q.front());
        q.pop();
    }
    cout << counts;
}