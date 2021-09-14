// 2013 Jan Contest Gold
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    int N, K;
    cin >> N >> K;
    vector<int> c(N);
    for (int i=0;i<N;i++){
        cin >> c[i];
    }
    int l=0,r=0;
    set<pair<int,int> > cc;
    int maxi = 0;
    while (r<N){
        if (cc.size()>K+1){
            auto itr = cc.upper_bound(pair<int,int>(c[l],-1));
            int store;
            if (itr->second==1){
                cc.erase(itr);
            }else{
                store=itr->second-1;
                cc.erase(itr);
                cc.insert(pair<int,int>(c[l],store));
            }
            l++;
        }else{
            if (r<N-1) r++;
            else break;
            auto itr = cc.upper_bound(pair<int,int>(c[r],-1));
            if (itr==cc.end()){
                maxi=max(maxi,1);
                cc.insert(pair<int,int>(c[r],1));
            }else{
                if (itr->first==c[r]){
                    int store = itr->second+1;
                    maxi=max(maxi,store);
                    cc.erase(itr);
                    cc.insert(pair<int,int>(c[r],store));
                }else{
                    maxi=max(maxi,1);
                    cc.insert(pair<int,int>(c[r],1));
                }
            }
        }
    }
    cout << maxi << "\n";
}