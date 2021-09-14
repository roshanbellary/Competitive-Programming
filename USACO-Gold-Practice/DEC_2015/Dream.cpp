#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("dream.in","r",stdin);
    freopen("dream.out","w",stdout);
    int N, M; cin >> N >> M;
    vector<vector<int>> g(N,vector<int>(M,0));
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> g[i][j];
        }
    }
    int dp[N][M][2]; //i references position, j references position, k references whether they smell like oranges or not
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            dp[i][j][0]=1e9;
            dp[i][j][1]=1e9;
        }
    }
    queue<pair<pair<pair<int,int>,pair<int,bool>>,pair<int,int>>> q;
    int diffx[4]={-1,0,1,0};
    int diffy[4]={0,-1,0,1};
    q.push(make_pair(make_pair(make_pair(0,0),make_pair(0,0)),make_pair(0,0)));
    while (!q.empty()){
        int i = q.front().first.first.first;
        int j = q.front().first.first.second;
        int d = q.front().first.second.first;
        int o = q.front().first.second.second;
        int dx = q.front().second.first;
        int dy = q.front().second.second;
        q.pop();
        if (g[i][j]==2) o=1;
        if (g[i][j]==4) o=0;
        if ((d>=dp[i][j][o])&&(g[i][j]!=4)) continue;
        if (d<dp[i][j][o]) dp[i][j][o]=d;
        if (g[i][j]!=4){
            for (int k=0;k<4;k++){
                if ((i+diffx[k]>=0)&&(i+diffx[k]<N)&&(j+diffy[k]>=0)&&(j+diffy[k]<M)){
                    if (!((!o&&(g[i+diffx[k]][j+diffy[k]]==3))||(g[i+diffx[k]][j+diffy[k]]==0))){
                            if (dp[i+diffx[k]][j+diffy[k]][o]>d+1){
                                q.push(make_pair(make_pair(make_pair(i+diffx[k],j+diffy[k]),make_pair(d+1,o)),make_pair(diffx[k],diffy[k])));
                            }
                    }
                }   
            }
        }else{
            bool w = false;
            if ((i+dx>=0)&&(i+dx<N)&&(j+dy>=0)&&(j+dy<M)){
                if (!((!o&&(g[i+dx][j+dy]==3))||(g[i+dx][j+dy]==0))){
                    w=true;
                    if (dp[i+dx][j+dy][o]>d+1){
                        q.push(make_pair(make_pair(make_pair(i+dx,j+dy),make_pair(d+1,o)),make_pair(dx,dy)));
                    }
                }
            }
            if (!w){
                for (int k=0;k<4;k++){
                    if ((i+diffx[k]>=0)&&(i+diffx[k]<N)&&(j+diffy[k]>=0)&&(j+diffy[k]<M)){
                        if (!((!o&&(g[i+diffx[k]][j+diffy[k]]==3))||(g[i+diffx[k]][j+diffy[k]]==0))){
                            if (dp[i+diffx[k]][j+diffy[k]][o]>d+1){
                                q.push(make_pair(make_pair(make_pair(i+diffx[k],j+diffy[k]),make_pair(d+1,o)),make_pair(diffx[k],diffy[k])));
                            }
                        }
                    }   
                }
            }
        }
    }
    if ((dp[N-1][M-1][0]==1e9)&&(dp[N-1][M-1][1]==1e9)){
        cout << "-1\n";
    }else{
        cout << min(dp[N-1][M-1][0],dp[N-1][M-1][1]) << "\n";
    }
}