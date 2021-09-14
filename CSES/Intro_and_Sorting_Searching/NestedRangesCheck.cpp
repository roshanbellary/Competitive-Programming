#include <bits/stdc++.h>
using namespace std;
class Range{
    public:
        int s,f;
        bool t = false;
        int i;
        const bool operator<(const Range &a){
            if (s!=a.s) return (s<a.s);
            else return (f<a.f);
        }
};
vector<pair<int,Range>> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N; cin >> N;
    for (int i=0;i<N;i++){
        Range n;
        int s, f; cin >> s >> f;
        n.s=s;n.f=f;
        n.i=i;
        v.push_back(make_pair(s,n));
        v.push_back(make_pair(f,n));
    }
    sort(v.begin(),v.end());
    multiset<pair<int,Range>> sq;
    for (int i=0;i<2*N;i++){
        if (v[i].second.s==v[i].first){
            sq.insert(make_pair(v[i].second.s,v[i].second));
        }else{
            if (sq.find(make_pair(v[i].second.s,v[i].second))!=sq.begin()){
                v[i].second.t=true;
            }
            sq.erase(make_pair(v[i].second.s,v[i].second));
        }
    }
    vector<bool> cont(N,false);
    for (int i=0;i<2*N;i++){
        cont[v[i].second.i]=v[i].second.t;
    }
    
}