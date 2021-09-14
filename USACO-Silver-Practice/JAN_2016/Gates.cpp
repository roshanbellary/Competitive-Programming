#include <iostream>
#include <vector>
using namespace std;
int N;
int grid=100;
vector<vector<bool> > g(2*grid+1);
int regions = 0;
void floodfill(int i, int j){
    if (i<0||i>2*grid||j<0||j>2*grid){ return;}
    if (g[i][j]) return;
    g[i][j]=true;
    floodfill(i-1,j);
    floodfill(i+1,j);
    floodfill(i,j-1);
    floodfill(i,j+1);
}
int main(){
    freopen("gates.in","r",stdin);
    freopen("gates.out","w",stdout);
    cin >> N;
    int x=grid;
    int y=grid;
    for (int i=0;i<2*grid+1;i++){
        g[i]=vector<bool>(2*grid+1);
    }
    g[x][y]=true;
    for (int i=0;i<N;i++){
        char c;
        cin >> c;
        if (c=='N') y-=1;
        if (c=='S') y+=1;
        if (c=='E') x+=1;
        if (c=='W') x-=1;
        g[x][y]=true;
        if (c=='N') y-=1;
        if (c=='S') y+=1;
        if (c=='E') x+=1;
        if (c=='W') x-=1;
        g[x][y]=true;
    }
    for (int i=0;i<2*grid+1;i++){
        for (int j=0;j<2*grid+1;j++){
            if (!g[i][j]){
                floodfill(i,j);
                regions++;
            }
        }
    }
    cout << regions-1;
}