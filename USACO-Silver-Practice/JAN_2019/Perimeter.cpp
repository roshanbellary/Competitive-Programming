#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N;
vector<vector<bool> > c;
vector<vector<bool> > v;
int arean;
int maxa=0;
int maxp=0;
int perimn;
int floodfill(int i, int j){
    if (i<0||j<0||i>=N||j>=N||!c[i][j]) return -1;
    if (v[i][j]) return 0;
    arean++;
    v[i][j]=true;
    int a,b,c,d;
    a=floodfill(i-1,j);
    b=floodfill(i+1,j);
    c=floodfill(i,j-1);
    d=floodfill(i,j+1);
    if (a==0) a=0;
    else a=max(1,a);
    if (b==0) b=0;
    else b=max(1,b);
    if (c==0) c=0;
    else c=max(1,c);
    if (d==0) d=0;
    else d=max(1,d);
    return (a+b+c+d);
}
int main(){
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        c.push_back(vector<bool>());
        v.push_back(vector<bool>());
        string store;
        cin >> store;
        for (int j=0;j<N;j++){
            v[i].push_back(false);
            if (store.substr(j,1)=="#") c[i].push_back(true);
            else c[i].push_back(false);
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (!v[i][j]){
                arean=0;
                perimn=floodfill(i,j);
                if (maxa==arean){
                    if (perimn<maxp){
                        maxp=perimn;
                    }
                }else if (arean>maxa){
                    maxp=perimn;
                    maxa=arean;
                }
            }
        }
    }
    cout << maxa << " " << maxp;
}