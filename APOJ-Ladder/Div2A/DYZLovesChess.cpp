#include <bits/stdc++.h>
using namespace std;
char c[2] = {'B','W'};
int N, M;
vector<vector<char>> r;
vector<vector<bool>> g;
void dfs(int p, int x, int y){
    if (x<0||x>=N||y<0||y>=M) return;
    if (!g[x][y]||(r[x][y]!='-')) return;
    r[x][y]=c[p];
    if (p==1) p=0;
    else p=1;
    dfs(p,x-1,y);
    dfs(p,x+1,y);
    dfs(p,x,y-1);
    dfs(p,x,y+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i=0;i<N;i++) g.push_back(vector<bool>(M));
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            char c; cin >> c;
            g[i][j]=(c=='.');
        }
    }
    for (int i=0;i<N;i++) r.push_back(vector<char>(M,'-'));
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            dfs(0,i,j);
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cout << r[i][j];
        }
        cout << "\n";
    }

}