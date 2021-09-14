#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
class Cow{
    public:
        int t,a,s;
};
class Compare{
    public:
        bool operator()(Cow &a, Cow &b){
            return (a.s<b.s);
        }
};
bool sorts(Cow &a, Cow &b){
    return (a.a<b.a);
}
bool operators(Cow &a,Cow &b){
    return (a.a<b.a);
}
priority_queue<Cow, vector<Cow>,Compare> q;
vector<Cow> f;
int main(){
    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        Cow store;
        int t,a;
        cin >> a >> t;
        store.t=t;
        store.a=a;
        store.s=-i;
        f.push_back(store);
    }
    sort(f.begin(),f.end(),sorts);
    int start = f[0].a;
    int dur = f[0].t;
    int index = 1;
    int wait = 0;
    while (index<N){
        while ((f[index].a<start+dur)&&(index<N)){
            q.push(f[index]);
            index++;
        }
        if (!q.empty()){
            wait = max(start+dur-q.top().a,wait);
            start+=dur;
            dur=q.top().t;
            q.pop();
        }else{
            start=f[index].a;
            dur=f[index].t;
            index++;
        }
    }
    cout << wait;
}