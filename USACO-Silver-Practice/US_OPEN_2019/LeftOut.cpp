#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int> > a;
bool change = false;
void flipc(int j){
    for (int i=0;i<N;i++){
        a[i][j]=!a[i][j];
    }
}
void flipr(int i){
    for (int j=0;j<N;j++){
        a[i][j]=!a[i][j];
    }
}
int main(){
    freopen("leftout.in","r",stdin);
    freopen("leftout.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        a.push_back(vector<int>());
    }
    for (int i=0;i<N;i++){
        string store;
        cin >> store;
        for (int j=0;j<store.length();j++){
            if (store.substr(j,1)=="R"){
                a[i].push_back(1);
            }else{
                a[i].push_back(0);
            }
        }
    }
    for (int i=0;i<N;i++){
        if (a[0][i]==1){
            flipc(i);
        }
    }
    for (int i=1;i<N;i++){
        if (a[i][0]==1){
            flipr(i);
        }
    }
    bool tl = true;
    for (int i=1;i<N;i++){
        for (int j=1;j<N;j++){
            if (!a[i][j]){
                tl=false;
                break;
            }
        }
    }
    bool r = false;
    int index = -1;
    for (int i=1;i<N;i++){
        bool f = true;
        for (int j=1;j<N;j++){
            if (!a[i][j]){
                f=false;
            }
        }
        if (f){
            r=true;
            index=i;
            break;
        }
    }
    bool c = false;
    int index2 = -1;
    for (int i=1;i<N;i++){
        bool f=true;
        for (int j=1;j<N;j++){
            if (!a[j][i]){
                f=false;
            }
        }
        if (f){
            c=true;
            index2=i;
            break;
        }
    }
    int x,y;
    bool p = false;
    for (int i=1;i<N;i++){
        for (int j=1;j<N;j++){
            if (a[i][j]){
                p=true;
                x=i;
                y=j;
                break;
            }
        }
    }
    if (tl){
        cout << "1 1";
    }else{
        if (r||c){
            if (r) cout << index+1 << " " << 1;
            if (c) cout << 1 << " " << index2+1;
        }else if (p){
            cout << x+1 << " " << y+1;
        }else{
            cout << -1;
        }
    }
    
}