#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<pair<int,int>> n;
    for (int i=0;i<N;i++){
        int x; cin >> x; n.push_back(make_pair(x,i));
    }
    sort(n.begin(),n.end());
    set<pair<int,int>> p;
    int result[N];
    for (int i=0;i<N;i++){
        if (p.size()==0) result[n[i].second]=0,p.insert(make_pair(n[i].second,n[i].first));
        else{
            auto itr = p.upper_bound(make_pair(n[i].second,n[i].first));
            if (itr==p.begin()){
                result[n[i].second]=0;
            }else{
                itr--;
                if (itr->second!=n[i].first){
                    result[n[i].second]=itr->first+1;
                }else{
                    result[n[i].second]=result[itr->first];
                }
            }
            p.insert(make_pair(n[i].second,n[i].first));
        }
    }
    for (int j:result){
        cout << j << " ";
    }cout << "\n";
}