#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<pair<int,int>> l;
    for (int i=0;i<N;i++){
        int a, b; cin >> a >> b;
        l.push_back(make_pair(a,b));
    }
    sort(l.begin(),l.end());
    set<int> p;
    bool w = false;
    for (int i=0;i<N;i++){
        if (p.size()==0) p.insert(l[i].second);
        else{
            if (p.upper_bound(l[i].second)!=p.end()){
                w=true;
                break;
            }
            p.insert(l[i].second);
        }
    }
    if (w) cout << "Happy Alex\n";
    else cout << "Poor Alex\n";
}