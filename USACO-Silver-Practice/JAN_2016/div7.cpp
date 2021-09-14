#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
    int N;
    cin >> N;
    int a[N];
    int store;
    int mins[7] = {0,50001,50001,50001,50001,50001,50001};
    int maxs[7] = {-1,-1,-1,-1,-1,-1,-1};
    for (int i=0;i<N;i++){
        cin >> store;
        if (i==0){
            a[0]=(store%7);
        }else{ 
            a[i]=(a[i-1]+store)%7;
        }
        mins[a[i]]=min(i, mins[a[i]]);
        maxs[a[i]]=max(i,maxs[a[i]]);
    }
    int maximum = 0;
    for (int i=0;i<7;i++){
        if ((maxs[i]!=(-1))&&(mins[i]!=pow(10,9))&&(maxs[i]!=mins[i])){
            maximum = max(maximum, maxs[i]-mins[i]);
        }
    }
    cout << maximum;
    return 0;
}