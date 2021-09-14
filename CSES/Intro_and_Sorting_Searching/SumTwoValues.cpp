#include <bits/stdc++.h>
using namespace std;
class Values{
    public:
        int v,ind;
};
bool sorts(Values &a, Values &b){
    return a.v<b.v;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N, X;
    cin >> N >> X;
    vector<Values> v(N);
    for (int i=0;i<N;i++){
        Values store;
        int val;
        cin >> val;
        store.v=val;
        store.ind=i;
        v[i]=store;
    }
    sort(v.begin(),v.end(),sorts);
    bool works = false;
    for (int i=0;i<N;i++){
        int a = i; int b = N-1;
        while (a!=b){
            int mid =(a+b+1)/2;
            if (v[i].v+v[mid].v<=X){
                a=mid;
            }else{
                b=mid-1;
            }
        }
        if (i==a) continue;
        if (v[i].v+v[a].v==X){
            works=true;
            cout << v[i].ind+1<<  " " << v[a].ind+1<< "\n";
        }
    }
    if (!works) cout << "IMPOSSIBLE" << "\n";
}