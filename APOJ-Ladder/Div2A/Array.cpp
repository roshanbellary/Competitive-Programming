#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int v[N]; int po = 0;
    for (int i=0;i<N;i++){cin >> v[i]; if (v[i]>0) po++;}
    bool r = false;
    vector<int> n;
    vector<int> p;
    vector<int> z;
    for (int i=0;i<N;i++){
        if ((v[i]<0)&&(!r)){
            r=true;
            n.push_back(v[i]);
            continue;
        }else if ((po==0)&&(p.size()<2)&&(v[i]<0)){
            p.push_back(v[i]);
            continue;
        }
        if (v[i]>0)p.push_back(v[i]);
        else z.push_back(v[i]);
    }
    cout << n.size() << " ";for (int j:n) cout << j << " ";
    cout << "\n";
    cout << p.size() << " ";for (int j:p) cout << j << " ";
    cout << "\n";
    cout << z.size() << " ";for (int j:z) cout << j << " ";
    cout << "\n";
}