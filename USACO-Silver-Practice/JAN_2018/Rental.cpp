#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Store{
    public:
        long long g;
        long long p;
};
vector<long long> cow;
vector<long long> rent;
vector<Store> stores;
int N, M, R;
bool sorts(Store &a, Store &b){
    return (a.p)<(b.p);
}
int main(){
    freopen("rental.in","r",stdin);
    freopen("rental.out","w",stdout);
    cin >> N >> M >> R;
    for (int i=0;i<N;i++){
        long long store;
        cin >> store;
        cow.push_back(store);
    }
    sort(cow.begin(),cow.end());
    vector<long long> value;
    for (int i=0;i<M;i++){
        Store store;
        long long g, p;
        cin >> g >> p;
        store.g=g;store.p=p;
        stores.push_back(store);
    }
    sort(stores.begin(),stores.end(),sorts);
    for (int i=0;i<M;i++){
        if (i==0) value.push_back(stores[0].g);
        else value.push_back(value[i-1]+stores[i].g);
    }
    for (int i=0;i<R;i++){
        long long store;
        cin >> store; 
        rent.push_back(store);
    }
    sort(rent.begin(),rent.end());
    vector<long long> price;
    price.push_back(rent[0]);
    for (int i=1;i<R;i++){
        price.push_back(price[i-1]+rent[i]);
    }
    int ci=N-1;
    int mi=M-2;
    long long tank = cow[N-1];
    vector<long long> money(N);
    long long pay = 0;
    while ((ci>=0)&&(mi>=0)){
        if (tank>=value[M-1]-value[mi]){
            pay+=stores[mi+1].p*stores[mi+1].g;
            mi--;
        }else{
            money[ci]=pay+(tank-value[M-1]+value[mi+1])*stores[mi+1].p;
            ci--;
            if (ci>=0) tank+=cow[ci];
        }
    }
    for (int i=0;i<=ci;i++){
        money[i]=pay;
    }
    long long maximum=0;
    for (int i=N-1;i>=0;i--){
        if (i>=R){
            if (maximum<price[R-1]+money[i]){maximum=price[R-1]+money[i];}
        }else{
            if (maximum<price[R-1]-price[R-i-1]+money[i]) maximum=price[R-1]-price[R-i-1]+money[i];
        }
    }
    cout << maximum;
}