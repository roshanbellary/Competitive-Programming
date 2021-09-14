#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("recording.in","r",stdin);
    freopen("recording.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<pair<int,int>> r;
    for (int i=0;i<N;i++){
        int s,f; cin >> s >> f;
        r.push_back(make_pair(f,s));
    }
    int counts = 0;
    sort(r.begin(),r.end());
    int e1 = 0;
    int e2 = 0;
    for (int i=0;i<N;i++){
        if (r[i].second<e1){
            continue;
        }else if (r[i].second<e2){
            e1=e2;
            e2=r[i].first;
            counts++;
        }else{
            e2=r[i].first;
            counts++;
        }
    }
    cout << counts << "\n";
}