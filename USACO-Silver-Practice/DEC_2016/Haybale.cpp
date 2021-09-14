#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> b;
int N, Q;
int main(){
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    cin >> N >> Q;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        b.push_back(store);
    }
    sort(b.begin(),b.end());
    for (int i=0;i<Q;i++){
        int s,f;
        cin >> s >> f;
        int a = 0;
        int c = N-1;
        while (a!=c){
            int mid = (a+c)/2;
            if (b[mid]>=s){
                c=mid;
            }else{
                a=mid+1;
            }
        }
        int d = 0;
        int e = N-1;
        while (d!=e){
            int mid = (d+e+1)/2;
            if (b[mid]<=f){
                d=mid;
            }else{
                e=mid-1;
            }
        }
        if ((b[d]>=s)&&(b[a]<=f)){
            cout << (abs(d-a)+1);
        }else{
            cout << 0;
        }
        if (i!=Q-1){
            cout << endl;
        }
    }
}