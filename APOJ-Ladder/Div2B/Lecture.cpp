#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    set<pair<string,string>> s;
    for (int i=0;i<M;i++){
        string a,b;
        cin >> a >> b;
        s.insert(make_pair(a,b));
    }
    string res;
    for (int i=0;i<N;i++){
        string a; cin >> a;
        auto itr = s.upper_bound(make_pair(a,"A"));
        if ((itr->first).length()<=(itr->second).length()){
            res+=(itr->first+" ");
        }else res+=(itr->second+" ");
    }
    cout << res << "\n";
}