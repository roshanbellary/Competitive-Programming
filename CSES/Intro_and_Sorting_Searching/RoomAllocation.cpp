#include <bits/stdc++.h>
using namespace std;
class Cust{
    public:
        double t;
        int id;
        bool ty;
};
bool sorts(Cust &a, Cust &b){
    return a.t<b.t;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    set<int> rooms;
    int counts = 0;
    vector<Cust> t;
    for (int i=0;i<N;i++){
        Cust store1;
        Cust store2;
        store1.id=i;
        store2.id=i;
        store1.ty=true;
        store2.ty=false;
        double a,b;
        cin >> a >> b;
        store1.t=a-0.5;
        store2.t=b;
        t.push_back(store1);
        t.push_back(store2);
    }
    vector<int> taken(N);
    sort(t.begin(),t.end(),sorts);
    for (int i=0;i<2*N;i++){
        if (t[i].ty){
            if (rooms.size()==0){
                counts++;
                taken[t[i].id]=counts;
            }else{
                taken[t[i].id]=*rooms.begin();
                rooms.erase(rooms.begin());
            }
        }else{
            rooms.insert(taken[t[i].id]);
        }
    }
    cout << counts << "\n";
    for (int i=0;i<N;i++){
        cout << taken[i] << " ";
    }
}