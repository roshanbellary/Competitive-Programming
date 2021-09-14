#include <bits/stdc++.h>
using namespace std;
int minimum=1000000000;
int steps;
vector<vector<bool> > vis;
vector<vector<int> > alt;
int N;
int counts = 0;
void dfs(int i, int j, int dist, int previ, int prevj){
    if (i<0||i>=N||j<0||j>=N) return;
    if (vis[i][j]||(abs(alt[i][j]-alt[previ][prevj])>dist)) return;
    vis[i][j]=true;
    counts++;
    dfs(i-1,j,dist,i,j);
    dfs(i+1,j,dist,i,j);
    dfs(i,j+1,dist,i,j);
    dfs(i,j-1,dist,i,j);
}
bool check(int d){
    for (int a=0;a<N;a++){
        fill(vis[a].begin(),vis[a].end(),false);
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (!vis[i][j]){
                counts=0;
                dfs(i,j,d,i,j);
                if (counts>=steps){
                    return true;
                }
            }
            counts=0;
        }
    }
    return false;
}
int main(){
    freopen("tractor.in","r",stdin);
    freopen("tractor.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        vis.push_back(vector<bool>(N,false));
        alt.push_back(vector<int>(N));
    }
    int maximum = 0;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> alt[i][j];
            maximum = max(maximum,alt[i][j]);
        }
    }
    if (N%2==1) steps=(N*N/2)+1;
    else steps = (N*N/2);
    int a=0;
    int b=maximum;
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