#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,C;
vector<int> a;
bool check(int t){
    int buses = 1;
    int start = a[0];
    int i = 1;
    int temp = 0;
    while (i<N){
        if ((a[i]-a[temp]>t)||(i-temp+1>C)){
            buses++;
            start=a[i];
            temp=i;
            i++;
        }else{
            i++;
        }
    }
    return (buses<=M);
}
int main(){
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);
    cin >> N >> M >> C;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        a.push_back(store);
    }
    sort(a.begin(),a.end());
    int s = 0;
    int b = 1000000000;
    while (s!=b){
        int mid = (s+b)/2;
        if (check(mid)){
            b=mid;
        }else{
            s=mid+1;
        }
    }
    cout << b;
}