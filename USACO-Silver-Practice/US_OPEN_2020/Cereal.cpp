#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<pair<int,int> > pref;
vector<int> taken;
bool shifts(int i, int position){
    int k = taken[position];
    if (k<i){
        return false;
    }
    taken[position]=i;
    if (pref[k].second!=position){
        if (taken[pref[k].second]<0){
            taken[pref[k].second]=k;
            return true;
        }else{
            return shifts(k, pref[k].second);
        }
    }else{
        return false;
    }
}
int main(){
    freopen("cereal.in","r",stdin);
    freopen("cereal.out","w",stdout);
    cin >> N >> M;
    for (int i=1;i<=M;i++){
        taken.push_back(-1);
    }
    for (int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        pref.push_back(pair<int,int>(a,b));
    }
    vector<int> results(N);
    int count = 0;
    for (int i=N-1;i>=0;i--){
        int temp = i;
        int position = pref[i].first;
        if (taken[position]>=0){
            if (shifts(i,position)){
                count++;
            }
        }else{
            taken[position]=i;
            count++;
        }
        results[i]=count;
    }
    for (int i=0;i<N;i++){
        cout << results[i] << endl;
    }
}