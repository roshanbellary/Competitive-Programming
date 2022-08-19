#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int,bool>> c;
int counts;
bool check(int r){
    int i = 0;
    int count = 0;
    bool w = true; bool prev=true;
    for (int i=0;i<N;i++){
        if (c[i].second){
            if (!prev){
                if (c[i-1].second>=c[i].second-r) return false;
            }
            int j = i+1; count++;
            while (j<N){
                if (c[j].first<=c[j-1].first+r){
                    if (!c[j].second){return false;}
                }else{
                    break;
                }
                prev=c[j].second;
                j++;
            }
            i=j-1;
        }
    }
    counts=count;
    return true;
}
int main(){
    freopen("socdist2.in","r",stdin);
    freopen("socdist2.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        int x, s;
        cin >> x >> s;
        if (s==1) c.push_back(make_pair(x,true));
        else c.push_back(make_pair(x,false));
    }
    sort(c.begin(),c.end());
    int s = 0;
    int f = 1e9;
    while (s!=f){
        int mid = (s+f+1)/2;
        if (check(mid)){
            s=mid;
        }else f=mid-1;
    }
    check(s);
    cout << counts << "\n";
}