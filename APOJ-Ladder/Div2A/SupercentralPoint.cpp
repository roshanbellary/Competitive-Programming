#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<pair<int,int>> p;
    for (int i=0;i<N;i++){
        int x,y; cin >> x >> y;
        p.push_back(pair<int,int>(x,y));
    }
    int counts = 0;
    for (int i=0;i<N;i++){
        int r=0,l=0,b=0,a=0;
        int cx = p[i].first; int cy = p[i].second;
        for (int j=0;j<N;j++){
            if (j==i) continue;
            int nx = p[j].first; int ny = p[j].second;
            if ((nx==cx)&&(ny<cy)) b++;
            if ((nx==cx)&&(ny>cy)) a++;
            if ((ny==cy)&&(nx<cx)) l++;
            if ((ny==cy)&&(nx>cx)) r++;
        }
        if ((b>0)&&(a>0)&&(l>0)&&(r>0)) counts++;
    }
    cout << counts << "\n";
}