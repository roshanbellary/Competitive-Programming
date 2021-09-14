#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Stop{
    public:
        int c;
        int x;
};
bool sorts(Stop& a, Stop& b){
    return (a.c>b.c);
}
int main(){
    freopen("reststops.in","r",stdin);
    freopen("reststops.out","w",stdout);
    long L,N,b,j;
    cin >> L >> N >> b >> j;
    vector<Stop> r(N);
    for (int i=0;i<N;i++){
        int x, c;
        cin >> x >> c;
        Stop store;
        store.x=x;
        store.c=c;
        r.push_back(store);
    }
    sort(r.begin(),r.end(),sorts);
    long temp = 0;
    long units = 0;
    for (int i=0;i<N;i++){
        if (r[i].x>temp){
            int diff = r[i].x-temp;
            units+=diff*(b-j)*r[i].c;
            temp=r[i].x;
        }
    }
    cout << units;
    return 0;
}