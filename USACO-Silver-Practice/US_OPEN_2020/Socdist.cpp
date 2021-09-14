#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N, M;
class Interval{
    public:
        ll s,f;
};
vector<Interval> r;
bool check(ll d){
    ll start = r[0].s;
    int index = 0;
    int placed = 1;
    while ((index<M)){
        if (start+d>r[index].f){
            index++;
        }else if (start+d>=r[index].s){
            placed++;
            start+=d;
        }else{
            start=r[index].s;
            placed++;
        }
    }
    return (placed>=N);
}
bool sorts(Interval &a, Interval &b){
    return a.s<b.s;
}
int main(){
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);
    cin >> N >> M;
    for (int i=0;i<M;i++){
        ll s,f;
        cin >> s >> f;
        Interval store;
        store.s=s;
        store.f=f;
        r.push_back(store);
    }
    sort(r.begin(),r.end(),sorts);
    ll a = 1;
    ll b = 1e18;
    while (a!=b){
        ll mid = (a+b+1)/2;
        if (check(mid)){
            a=mid;
        }else{
            b=mid-1;
        }
    }
    cout << a;
}