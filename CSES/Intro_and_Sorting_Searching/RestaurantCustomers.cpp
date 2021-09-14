#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    vector<pair<int,int> > r;
    for (int i=0;i<N;i++){
        int s, f;
        cin >> s >> f;
        r.push_back(pair<int,int>(s,1));
        r.push_back(pair<int,int>(f,-1));
    }
    sort(r.begin(),r.end());
    int maximum = 0;
    int count = 0;
    for (int i=0;i<2*N;i++){
        count+=r[i].second;
        maximum=max(maximum,count);
    }
    cout << maximum;
}