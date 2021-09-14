#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,K,B;
vector<int> b;
bool check(int fix){
    if (fix!=B){
        int maxInt = 0;
        maxInt = max(maxInt,b[fix]-1);
        for (int i=0;i<=B-1-fix;i++){
            maxInt = max(maxInt, b[i+fix+1]-b[i]);
        }
        maxInt = max(N-b[B-fix-1],maxInt);
        return (maxInt>=K);
    }else{
        return (N>=K);
    }
}
int main(){
    freopen("maxcross.in","r",stdin);
    freopen("maxcross.out","w",stdout);
    cin >> N >> K >> B;
    for (int i=0;i<B;i++){
        int store;
        cin >> store;
        b.push_back(store);
    }
    sort(b.begin(),b.end());
    int a=0;
    int b=B;
    while (a!=b){
        int mid = (a+b)/2;
        if (check(mid)){
            b=mid;
        }else{
            a=mid+1;
        }
    }
    cout << a;
}
