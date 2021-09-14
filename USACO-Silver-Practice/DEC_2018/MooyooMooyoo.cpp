#include <bits/stdc++.h>
using namespace std;
int N, K;
int counts = 0;
vector<vector<int> > g;
vector<vector<bool> > v;
void floodfill(int i, int j, int val){
    if (i<0||i>=N||j<0||j>=10) return;
    if (v[i][j]) return;
    if (g[i][j]==val){
        v[i][j]=true;
        counts++;
        floodfill(i-1,j,val);
        floodfill(i+1,j,val);
        floodfill(i,j-1,val);
        floodfill(i,j+1,val);
    }else{
        return;
    }

}
void exploding(int i, int j, int val){
    if (i<0||i>=N||j<0||j>=10) return;
    if (g[i][j]==val){
        g[i][j]=0;
        exploding(i-1,j,val);
        exploding(i+1,j,val);
        exploding(i,j-1,val);
        exploding(i,j+1,val);
    }
}
bool explode(){
    bool work = false;
    for (int i=0;i<N;i++){
        fill(v[i].begin(),v[i].end(),false);
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<10;j++){
            if (g[i][j]>0){
                counts=0;
                floodfill(i,j,g[i][j]);
                if (counts>=K){
                    work = true;
                    exploding(i,j,g[i][j]);
                }
            }
        }
    }
    return work;
}
void gravity(){
    for (int i=N-1;i>=0;i--){
        for (int j=9;j>=0;j--){
            if (g[i][j]>0){
                int z=i+1;
                while (z<N){
                    if (g[z][j]!=0){
                        break;
                    }
                    z++;
                }
                z--;
                if (z!=i){
                    g[z][j]=g[i][j];
                    g[i][j]=0;
                }
            }
        }
    }
}
int main(){
    freopen("mooyomooyo.in","r",stdin);
    freopen("mooyomooyo.out","w",stdout);
    cin >> N >> K;
    for (int i=0;i<N;i++){
        g.push_back(vector<int>(10));
        v.push_back(vector<bool>(10));
    }
    for (int i=0;i<N;i++){
        string store;
        cin >> store;
        for (int j=0;j<10;j++){
            g[i][j]=store[j]-'0';
        }
    }
    bool did = true;
    while (did){
        gravity();
        did=explode();
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<10;j++){
            cout << g[i][j];
        }
        cout << endl;
    }
}