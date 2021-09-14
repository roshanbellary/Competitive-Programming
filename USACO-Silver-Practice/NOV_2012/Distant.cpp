#include <bits/stdc++.h>
using namespace std;
int N, A, B;
priority_queue<pair<int, pair<int,int> > > pq;
char grid[30][30];
bool v[30][30];
int result = 0;
void addV(int nx, int ny, int x, int y, int m){
    if (nx<0||nx>N-1||ny<0||ny>N-1) return;
    if (v[nx][ny]) return;
    if (grid[nx][ny]==grid[x][y]) pq.push(pair<int,pair<int,int>>(m-A,pair<int,int>(nx,ny)));
    else  pq.push(pair<int,pair<int,int>>(m-B,pair<int,int>(nx,ny)));
}
int main(){
    freopen("distant.in","r",stdin);
    freopen("distant.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> A >> B;
    for (int i=0;i<N;i++){
        string store;
        cin >> store;
        for (int j=0;j<N;j++){
            grid[i][j]=store[j];
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            for (int a=0;a<N;a++){
                for (int b=0;b<N;b++){
                    v[a][b]=false;
                }
            }
            pq.push(pair<int,pair<int,int>>(0,pair<int,int>(i,j)));
            while (!pq.empty()){
                int m = pq.top().first;
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                pq.pop();
                if (v[x][y]) continue;
                v[x][y]=true;
                result=max(result,-m);
                addV(x-1,y,x,y,m);
                addV(x+1,y,x,y,m);
                addV(x,y-1,x,y,m);
                addV(x,y+1,x,y,m);
            }
        }
    }
    cout << result << "\n";
}