#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
vector<int> m;
int main(){
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        m.push_back(store);
    }
    sort(m.begin(),m.end());
    int minimum = 10000000;
    for (int i=0;i<101-17;i++){
        int cost = 0;
        for (int j=0;j<N;j++){
            if (m[j]<i){
                cost+=(i-m[j])*(i-m[j]);
            }
            if (m[j]>i+17){
                cost+=(m[j]-i-17)*(m[j]-i-17);
            }
        }
        minimum=min(minimum,cost);
    }
    cout << minimum;
}