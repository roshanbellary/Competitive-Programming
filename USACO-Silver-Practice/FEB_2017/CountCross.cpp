#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N,K,R;
vector<pair<int, int> > c;
map<pair<int,int>, int> cows;
int npairs;
vector<vector<bool> > v;
map<pair<pair<int, int>,pair<int,int> >, bool > r;
void floodfill(int i, int j, int previ, int prevj){
    if (i<0||i>=N||j<0||j>=N||v[i][j]||r[pair<pair<int,int>,pair<int,int> >(pair<int,int>(i,j),pair<int,int>(previ,prevj))]) return;
    v[i][j]=true;
    if (cows[pair<int,int>(i,j)]>0) npairs++;
    floodfill(i-1,j,i,j);
    floodfill(i+1,j,i,j);
    floodfill(i,j-1,i,j);
    floodfill(i,j+1,i,j);
}
int main(){
    freopen("countcross.in","r",stdin);
    freopen("countcross.out","w",stdout);
    cin >> N >> K >> R;
    for (int i=0;i<N;i++){
        v.push_back(vector<bool>(N));
    }
    for (int i=0;i<R;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        r[pair<pair<int,int>,pair<int,int> >(pair<int,int>(x2-1,y2-1),pair<int,int>(x1-1,y1-1))] = true;
        r[pair<pair<int,int>,pair<int,int> >(pair<int,int>(x1-1,y1-1),pair<int,int>(x2-1,y2-1))] = true;
    }
    for (int i=1;i<K+1;i++){
        int x,y;
        cin >> x >> y;
        c.push_back(pair<int,int>(x-1,y-1));
        cows[pair<int,int>(x-1,y-1)]=i;
    }
    for (int i=0;i<K;i++){
        for (int d=0;d<N;d++){
            fill(v[d].begin(),v[d].end(),false);
        }
        floodfill(c[i].first,c[i].second,c[i].first,c[i].second);
    }
    cout << (K*K-npairs)/2;
}