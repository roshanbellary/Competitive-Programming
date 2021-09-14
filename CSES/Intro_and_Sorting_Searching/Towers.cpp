#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int k[N];
    for (int i=0;i<N;i++){
        cin >> k[i];
    }
    multiset<int> mins;
    for (int i=0;i<N;i++){
        if (mins.size()==0)mins.insert(k[i]);
        else{
            set<int>::iterator itr = mins.upper_bound(k[i]);
            if (itr==mins.end()){
                mins.insert(k[i]);
            }else{
                mins.erase(itr);
                mins.insert(k[i]);
            }
        }
    }
    cout << mins.size() << "\n";
}