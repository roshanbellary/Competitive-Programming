#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int N;
int maxLen = 0;
vector<vector<string> > l;
vector<vector<bool> > v;
bool checkString(string store){
    if (store.length()%2==1) return false;
    string half1=store.substr(0,store.length()/2);
    string half2=store.substr(store.length()/2,store.length()/2);
    for (int i=0;i<store.length()/2;i++){
        if ((half1.substr(i,1)=="(")&&(half2.substr(i,1)==")")) continue;
        else return false;
    }
    return true;
}
void floodfill(int i, int j,vector<vector<bool> > v, string r){
    if (i<0||i>=N||j<0||j>=N) return;
    if (v[i][j]) return;
    v[i][j]=true;
    vector<vector<bool> > a;
    vector<vector<bool> > b;
    vector<vector<bool> > c;
    vector<vector<bool> > d;
    for (int i=0;i<N;i++){
        a.push_back(vector<bool>(N));
        b.push_back(vector<bool>(N));
        c.push_back(vector<bool>(N));
        d.push_back(vector<bool>(N));
    }
    for (int i=0;i<N;i++){
        a[i]=v[i];
        b[i]=v[i];
        c[i]=v[i];
        d[i]=v[i];
    }
    r+=l[i][j];
    if (checkString(r)){
        int x = r.length();
        maxLen=max(x,maxLen);
    }
    floodfill(i+1,j,a,r);
    floodfill(i,j+1,b,r);
    floodfill(i-1,j,c,r);
    floodfill(i,j-1,d,r);

}
int main(){
    freopen("hshoe.in","r",stdin);
    freopen("hshoe.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        l.push_back(vector<string>(N));
        v.push_back(vector<bool>(N));
    }
    for (int i=0;i<N;i++){
        string store;
        cin >> store;
        for (int j=0;j<N;j++){
            l[i][j]=store.substr(j,1);
        }
    }
    floodfill(0,0,v,"");
    cout << maxLen;
}