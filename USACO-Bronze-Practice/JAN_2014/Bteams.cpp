#include <iostream>
#include <vector>
using namespace std;
int s[12];
int t[12];
int v[4];
int totmin = 1000000;
void cases(int n){
    if (n==12){
        int ts[4]={0,0,0,0};
        for (int i=0;i<12;i++){
            ts[t[i]]+=s[i];
        }
        int maximum = max(max(max(ts[0],ts[1]),ts[2]),ts[3]);
        int minimum = min(min(min(ts[0],ts[1]),ts[2]),ts[3]);
        if ((totmin==-1)||(maximum-minimum<totmin)){
            totmin=maximum-minimum;
        }
        return;
    }
    for (int te=0;te<4;te++){
        if (v[te]<3){
            t[n]=te;
            v[te]++;
            cases(n+1);
            v[te]--;
        }
    }
}
int main(){
    freopen("bteams.in","r",stdin);
    freopen("bteams.out","w",stdout);
    for (int i=0;i<12;i++){
        int store;
        cin >> store;
        s[i]=store;
    }
    cases(0);
    cout << totmin;
}