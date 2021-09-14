#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
class Interval{
    public:
        int f,s;
};
bool sorts(Interval &a, Interval &b){
    return (a.f<b.f);
}
vector<Interval> a;
int main(){
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);
    cin >> N >> K;
    for (int i=0;i<K;i++){
        int s;
        cin >> s;
        int f;
        cin >> f;
        Interval store;
        store.s=min(s,f);
        store.f=max(s,f);
        a.push_back(store);
    }
    sort(a.begin(),a.end(),sorts);
    int photos=1;
    int temp = 0;
    for (int i=0;i<K;i++){
        if (i==0) photos++;
        else if (a[temp].f<=a[i].s){
            photos++;
            temp=i;
        }
    }
    cout << photos;
}