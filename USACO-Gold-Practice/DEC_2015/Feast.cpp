#include <bits/stdc++.h>
using namespace std;
const int sizes = 5e6;
int totmax = 0;
int T,A,B;
bool n[sizes];
int main(){
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    cin >> T >> A >> B;
    n[0]=true;
    for (int i=1;i<=T;i++){
        if (!n[i]){
            if ((i-A)<0) continue;
            else n[i]=n[i-A];
        }
    }
    for (int i=1;i<=T;i++){
        if (!n[i]){
            if ((i-B)<0) continue;
            else n[i]=n[i-B];
        }
    }
    for (int i=0;i<=T;i++){
        if (n[i]) n[i/2]=true;
    }
    for (int i=1;i<=T;i++){
        if (!n[i]){
            if ((i-A)<0) continue;
            else n[i]=n[i-A];
        }
    }
    for (int i=1;i<=T;i++){
        if (!n[i]){
            if ((i-B)<0) continue;
            else n[i]=n[i-B];
        }
    }
    for (int i=T;i>=0;i--){
        if (n[i]){totmax=i;break;}
    }
    cout << totmax << "\n";
}