#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,K;
vector<int> h;
bool check(int R){
    int k = 0;
    for (int i=0;i<N;i++){
        k++;
        int temp=i+1;
        for (int j=i+1;j<N;j++){
            if (h[j]-h[i]<=2*R){
                temp=j+1;
            }else{
                temp=j;
                break;
            }
        }
        i=temp-1;
    }
    return (k<=K);
}
int main(){
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin >> N >> K;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        h.push_back(store);
    }
    sort(h.begin(),h.end());
    int a = 0;
    int b = 500000000;
    while (a!=b){
        int mid = (a+b)/2;
        if (check(mid)){
            b=mid;
        }else{
            a=mid+1;
        }
    }
    cout << b;
}