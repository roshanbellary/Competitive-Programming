#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> ft;
void update(int i){
    while (i<=ft.size()){
        ft[i]++;
        i+=(i&(-i));
    }
}
int query(int i){
    return (i>0) ? (query(i-(i&(-i)))+ft[i]) : 0;
}
int32_t main(){
    freopen("haircut.in","r",stdin);
    freopen("haircut.out","w",stdout);
    int N; cin >> N;
    for (int i=0;i<N+2;i++) ft.push_back(0);
    int v[N];
    vector<int> res(N+1,0);
    vector<int> counts(N+1,0);
    for (int i=0;i<N;i++){
        cin >> v[i];
        counts[v[i]]++;
    }
    vector<int> countsdp(N+1,0);
    int prev = 0;
    for (int i=N;i>=0;i--){
        countsdp[i]=prev;
        prev+=counts[i];
    }
    vector<int> above(N+1,0);
    for (int i=N-1;i>=0;i--){
        res[v[i]]+=query(v[i]);
        above[v[i]]+=(countsdp[v[i]]-query(N+1)+query(v[i]+1));
        update(v[i]+1);
    }
    int totsum = 0;
    for (int j:res){
        totsum+=j;
    }
    int t = 0;
    for (int i=N;i>=0;i--){
        t+=above[i];
        above[i]=t;
    }
    for (int i=0;i<N;i++){
        cout << totsum-above[i] << "\n";
    }
}