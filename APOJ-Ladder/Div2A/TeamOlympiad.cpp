#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> v(N);
    for (int i=0;i<N;i++)
        cin >> v[i];
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    for (int i=0;i<N;i++){
        if (v[i]==1) v1.push_back(i+1);
        if (v[i]==2) v2.push_back(i+1);
        if (v[i]==3) v3.push_back(i+1);
    }
    int mini = min(v1.size(),min(v2.size(),v3.size()));
    cout << mini << "\n";
    if (mini!=0){
        for (int i=0;i<mini;i++){
            cout << v1[i] << " " << v2[i] << " " << v3[i] << "\n";
        }
    }
}