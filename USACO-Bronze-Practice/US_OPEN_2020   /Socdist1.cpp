#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("socdist1.in","r",stdin);
    freopen("socdist1.out","w",stdout);
    int N; cin >> N;
    string s; cin >> s;
    multiset<int> dist;
    vector<int> pos;
    for (int i=0;i<s.length();i++){
        if (s[i]=='1'){
            pos.push_back(i);
            int j = i+1;
            while (j<N){
                if (j=='1') break;
                j++;
            }
            if (j>i+1) dist.insert(j-i);
            i=j-1;
        }
    }
    int mini=1;
    if (dist.size()>0){
        if (pos[0]>0) dist.insert(pos[0]);
        if (s.length()-1-pos[pos.size()-1]>0) dist.insert(s.length()-1-pos[pos.size()-1]);
        auto itr = dist.rbegin();
        int val = *itr; 
        dist.erase(dist.find(val));
        if (val%2==0){
            dist.insert(val/2);dist.insert(val/2);
        }else{dist.insert(val/2), dist.insert(val/2+1);}
        itr = dist.rbegin();
        int val2 = *itr;
        dist.erase(dist.find(val2));
        if (val2%2==0){
            dist.insert(val2/2);dist.insert(val2/2);
        }else{dist.insert(val2/2), dist.insert(val2/2+1);}
        int mini = max(mini,*(dist.begin()));
        mini=max(mini,(val+1)/3);
    }
    cout << mini << "\n";
}