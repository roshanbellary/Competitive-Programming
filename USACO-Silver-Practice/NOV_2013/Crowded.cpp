#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    freopen("crowded.in","r",stdin);
    freopen("crowded.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, D; cin >> N >> D;
    vector<pair<int,int> > c;
    for (int i=0;i<N;i++){
        int x,h;
        cin >> x >> h;
        c.push_back(pair<int,int>(x,h));
    }
    sort(c.begin(),c.end());
    int count = 0;
    int j=0;
    set<pair<int,int> > be;
    set<pair<int,int> > ab;
    int k = 0;
    int s = 0;
    int temp = -1;
    for (int i=0;i<N;i++){
        while (j<N){
            if ((c[j].first>=c[i].first-D)&&(c[j].first<=c[i].first)){
                be.insert(pair<int,int>(c[j].second,c[j].first));
            }else if ((c[j].first<=c[i].first+D)&&(c[j].first>=c[i].first)){
                ab.insert(pair<int,int>(c[j].second,c[j].first));
            }else{
                break;
            }
            j++;
        }
        while (true){
            if (c[k].first<c[i].first-D){
                be.erase(pair<int,int>(c[k].second,c[k].first)); //erase by height
            }else{
                break;
            }
            k++;
        }
        while (true){
            if ((c[s].first>=c[i].first-D)&&(c[s].first<=c[i].first)){
                ab.erase(pair<int,int>(c[s].second,c[s].first));
                be.insert(pair<int,int>(c[s].second,c[s].first));
            }else{
                break;
            }
            s++;
        }
        auto itr = ab.upper_bound(pair<int,int>(2*c[i].second,0));
        auto itr1 = be.lower_bound(pair<int,int>(2*c[i].second,0));
        if ((itr1==be.end())||(itr==ab.end())) continue;
        pair<int,int> store = *itr;
        pair<int,int> store2 = *itr1;
        count++;
    }
    cout << count << "\n";
}