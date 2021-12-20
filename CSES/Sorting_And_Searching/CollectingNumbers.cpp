#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    vector<pair<int,int> > sv;
    for (int i=0;i<N;i++){
        int val;
        cin >> val;
        sv.push_back(pair<int,int>(val,i));
    }
    sort(sv.begin(),sv.end());
    int count = 1;
    for (int i=0;i<N-1;i++)
        if (sv[i+1].second<sv[i].second) count++;
    cout << count << "\n";
}