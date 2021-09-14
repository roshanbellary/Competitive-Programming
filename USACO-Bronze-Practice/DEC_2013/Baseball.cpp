#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> l;
bool check1(int mid, int i, int j){
    return (l[j]-l[mid])>=(l[mid]-l[i]);
}
bool check2(int mid, int i, int j){
    return (l[j]-l[mid])<=2*(l[mid]-l[i]);
}
int main(){
    freopen("baseball.in","r",stdin);
    freopen("baseball.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        l.push_back(store);
    }
    sort(l.begin(),l.end());
    int count = 0;
    for (int i=0;i<N;i++){
        for (int j=i+2;j<N;j++){
            int a,b;
            a=i;b=j;
            while (a!=b){
                int mid = (a+b+1)/2;
                if (check1(mid,i,j)){
                    a=mid;
                }else{
                    b=mid-1;
                }
            }
            int c,d;
            c=i;d=j;
            while (c!=d){
                int mid = (c+d)/2;
                if (check2(mid,i,j)){
                    d=mid;
                }else{
                    c=mid+1;
                }
            }
            if (c<=a){
                count+=(a-c+1);
            }
        }
    }
    cout << count;
}