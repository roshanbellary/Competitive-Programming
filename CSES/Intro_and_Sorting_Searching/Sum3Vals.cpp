#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,X;
    cin >> N >> X;
    vector<pair<int,int> > v;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        v.push_back(pair<int,int>(store,i));
    }
    sort(v.begin(),v.end());
    bool works = false;
    for (int i=0;i<N;i++){
        for (int j=i+2;j<N;j++){
            int a = i+1;
            int b = j-1;
            while (a!=b){
                int mid = (a+b)/2;
                if (v[j].first+v[i].first+v[mid].first>=X){
                    b=mid;
                }else{
                    a=mid+1;
                }
            }
            if ((a!=i)&&(a!=j)){
                if (v[i].first+v[j].first+v[a].first==X){
                    cout << v[i].second+1<< " " << v[a].second+1<< " " << v[j].second+1 << "\n";
                    works=true;
                    break;
                }
            }
        }
        if (works) break;
    }
    if (!works){
        cout << "IMPOSSIBLE" << "\n";
    }
}