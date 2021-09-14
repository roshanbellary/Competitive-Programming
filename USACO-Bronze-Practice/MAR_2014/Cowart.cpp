#include <iostream>
#include <vector>
int N;
using namespace std;
vector<vector<int> >a;
vector<vector<bool> >h;
vector<vector<bool> >c;
void floodfillh(int i, int j, int val){
    if ((i<0)||(i>=N)||(j<0)||(j>=N)) return;
    if (h[i][j]) return;
    if (a[i][j]!=val){return;}
    else{
        h[i][j]=true;
        floodfillh(i-1,j,val);
        floodfillh(i+1,j,val);
        floodfillh(i,j-1,val);
        floodfillh(i,j+1,val);
    }
}
void floodfillc(int i, int j, int val){
    if ((i<0)||(i>=N)||(j<0)||(j>=N)) return;
    if (c[i][j]) return;
    if ((a[i][j]%2)!=(val%2)){return;}
    else{
        c[i][j]=true;
        floodfillc(i-1,j,val);
        floodfillc(i+1,j,val);
        floodfillc(i,j-1,val);
        floodfillc(i,j+1,val);
    }
}
int main(){
    freopen("cowart.in","r",stdin);
    freopen("cowart.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        a.push_back(vector<int>(N));
        h.push_back(vector<bool>(N));
        c.push_back(vector<bool>(N));
    }
    for (int i=0;i<N;i++){
        string store;
        cin >> store;
        for (int j=0;j<N;j++){
            if (store.substr(j,1)=="R"){
                a[i][j]=0;
            }else if (store.substr(j,1)=="B") a[i][j]=1;
            else a[i][j]=2;
        }
    }
    int counth=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (!h[i][j]){
                counth++;
                floodfillh(i,j,a[i][j]);
            }
        }
    }
    int countc=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (!c[i][j]){
                countc++;
                floodfillc(i,j,a[i][j]);
            }
        }
    }
    cout << counth << " " << countc;
}