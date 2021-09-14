#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Cow{
    public:
        int s,e;
};
vector<int> c;
vector<Cow> cow;
bool sorts(Cow &a, Cow &b){
    return (a.e<b.e);
}
int main(){
    freopen("helpcross.in","r",stdin);
    freopen("helpcross.out","w",stdout);
    int N,C;
    cin >> C >> N;
    for (int i=0;i<C;i++){
        int store;
        cin >> store;
        c.push_back(store);
    }
    for (int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        Cow store;
        store.s=a;
        store.e=b;
        cow.push_back(store);
    }
    sort(cow.begin(),cow.end(),sorts);
    sort(c.begin(),c.end());
    int count=0;
    vector<bool> t(N);
    fill(t.begin(),t.end(),false);
    for (int i=0;i<C;i++){
        int time = c[i];
        int a = 0;
        int b = N-1;
        while (a!=b){
            int mid = (a+b)/2;
            if (cow[mid].e>=time){
                b=mid;
            }else{
                a=mid+1;
            }
        }
        for (int j=a;j<N;j++){
            bool d = t[j];
            if ((cow[j].s<=time)&&!d){
                t[j]=true;
                count++;
                break;
            }
        }
    }
    cout << count;
}