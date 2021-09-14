#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> c(2*N,0);
    for (int i=0;i<N;i++){
        int store; cin>>store;
        if (i<N/2) c[store-1]=2;// 2 is for the greater part
        else c[store-1]=1; // 1 is for lesser
    }
    vector<int> bfc;
    vector<int> blc;
    vector<int> co;
    for (int i=0;i<2*N;i++){
        if (c[i]==1){
            blc.push_back(i);
        }else if (c[i]==2){
            bfc.push_back(i);
        }else if (c[i]==0){
            co.push_back(i);
        }
    }
    int gw = 0;
    vector<int> fc;
    vector<int> lc;
    for (int i=0;i<N;i++){
        if (i<N/2) lc.push_back(co[i]); //sends smaller elements to lc
        else fc.push_back(co[i]); //sends larger elements to fc
    }
    int i=N/2-1; int j=N/2-1;
    while ((i>=0)&&(j>=0)){
        if (fc[i]>bfc[j]){
            gw++;i--;j--;
        }else{
            j--;
        }
    }
    i=0;j=0;
    while ((i<N/2)&&(j<N/2)){
        if (lc[i]<blc[j]){
            gw++; i++; j++;
        }else{
            j++;
        }
    }
    cout << gw << "\n";
}