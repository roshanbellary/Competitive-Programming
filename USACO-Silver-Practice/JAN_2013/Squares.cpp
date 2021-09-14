#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    freopen("squares.in","r",stdin);
    freopen("squares.out","w",stdout);
    int N, K;
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    vector<pair<int,int>> points;
    for (int i=0;i<N;i++){
        int x, y; cin >> x >> y;
        points.push_back(make_pair(x,y));
    }
    vector<pair<pair<int,int>,pair<bool,int>>> r;
    for (int i=0;i<N;i++){
        r.push_back(make_pair(make_pair(points[i].first-K/2+1,points[i].second),make_pair(true,points[i].first))); // sets adding parts
        r.push_back(make_pair(make_pair(points[i].first+K/2-1,points[i].second),make_pair(false,points[i].first)));
    }
    sort(r.begin(),r.end());
    set<pair<int,int>> ys;
    long long area = 0;
    bool w = false;
    bool m = false;
    for (int i=0;i<r.size();i++){
        if (!r[i].second.first){
            ys.erase(make_pair(r[i].first.second,r[i].second.second));
        }else{
            if (ys.size()==0){ys.insert(make_pair(r[i].first.second,r[i].second.second)); continue;}
            auto itr = ys.upper_bound(make_pair(r[i].first.second-K+1,-1e9-1));
            if (itr==ys.end()){
                ys.insert(make_pair(r[i].first.second,r[i].second.second));
                continue;
            }
            if (itr->first<r[i].first.second+K){
                if (!w) w=true;
                else{m=true;break;}
                area+=((K-abs(r[i].first.second-itr->first))*(K-abs(r[i].second.second-itr->second)));
            }
            itr++;
            if (itr==ys.end()){
                ys.insert(make_pair(r[i].first.second,r[i].second.second));
                continue;
            }
            if (itr->first<r[i].first.second+K){
                if (!w) w=true;
                else{m=true;break;}
                area+=((K-abs(r[i].first.second-itr->first))*(K-abs(r[i].second.second-itr->second)));
            }
            ys.insert(make_pair(r[i].first.second,r[i].second.second));
        }
    }
    if (m) cout << "-1\n";
    else if (w) cout << area << "\n";
    else cout << "0\n";
}