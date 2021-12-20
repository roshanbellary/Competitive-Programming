#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, X;
    cin >> N >> X;
    vector<pair<int,int> > v(N);
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        v[i]=pair<int,int>(store,i);
    }
    sort(v.begin(),v.end());
    bool works = false;
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            if (j+1>=N-1) break;
            int a=j+1;
            int b=N-1;
            while (a!=b){
                if (v[i].first+v[j].first+v[a].first+v[b].first<X){
                    a++;
                }else if (v[i].first+v[j].first+v[a].first+v[b].first>X){
                    b--;
                }else{
                    break;
                }
            }
            if (a!=b){
                cout << v[i].second+1 << " " << v[j].second+1 << " " << v[a].second+1 << " " << v[b].second+1 << "\n";
                works=true;
                break;
            }
        }
        if (works) break;
    }
    if (!works) cout << "IMPOSSIBLE\n";
}