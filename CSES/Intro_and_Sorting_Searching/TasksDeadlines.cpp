#include <bits/stdc++.h>
#define int long long
using namespace std;
int N;
class Task{
    public:
        int dl;
        int du;
};
bool sorts(Task &a, Task &b){
    return a.du<b.du;
}
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    vector<Task> schedule;
    for (int i=0;i<N;i++){
        int a,d;
        cin >> a >> d;
        Task store;
        store.dl=d;
        store.du=a;
        schedule.push_back(store);
    }
    sort(schedule.begin(),schedule.end(),sorts);
    int start = 0;
    int cost = 0;
    for (int i=0;i<N;i++){
        start+=schedule[i].du;
        cost+=(schedule[i].dl-start);
    }
    cout << cost << "\n";
}