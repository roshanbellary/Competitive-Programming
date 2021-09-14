#include <bits/stdc++.h>
using namespace std;
vector<int> ft;
void update(int i, int v){
    while (i<=ft.size()){
        ft[i]+=v;
        i+=(i&(-i));
    }
}
int query(int i){
    return (i>0) ? ft[i]+query(i-(i&(-i))):0;
}
int main(){
    freopen("circlecross.in","r",stdin);
    freopen("circlecross.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<pair<int,bool>> t;
    vector<bool> s(N,false);
    for (int i=0;i<2*N+1;i++){
        ft.push_back(0);
    }
    vector<int> p(N);
    for (int i=0;i<2*N;i++){
        int store; cin >> store;
        if (s[store-1]) t.push_back(make_pair(store,false));
        else t.push_back(make_pair(store,true)), s[store-1]=true, p[store-1]=i+1;
    }
    int sum = 0;
    for (int i=0;i<2*N;i++){
        if (t[i].second){
            update(i+1,1);
        }else{
            sum+=query(i+1)-query(p[t[i].first-1]);
            update(p[t[i].first-1],-1);
        }
    }
    cout << sum << "\n";
}