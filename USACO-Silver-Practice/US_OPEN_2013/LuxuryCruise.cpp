#include <bits/stdc++.h>
using namespace std;
int N, M, K;
vector<vector<int> > l;
vector<int> m;
int dfs(int i){
    int start = i;
    for (int i=0;i<M;i++){
        start = l[start][m[i]];
    }
    return start;
}
int main(){
    freopen("cruise.in","r",stdin);
    freopen("cruise.out","w",stdout);
    cin >> N >> M >> K;
    for (int i=0;i<N;i++){
        l.push_back(vector<int>());
    }
    for (int i=0;i<N;i++){
        int le, r;
        cin >> le >> r; le--; r--;
        l[i].push_back(le); l[i].push_back(r);
    }
    for (int i=0;i<M;i++){
        char c;
        cin >> c;
        if (c=='L') m.push_back(0);
        else m.push_back(1);
    }
    int start = 0;
    vector<int> loc = {0};
    for (int i=0;i<N+1;i++){
        start=dfs(start);
        loc.push_back(start);
    }
    int cyclel = 0;
    int shift = 0;
    bool done = false;
    for (int i=0;i<loc.size();i++){
        for (int j=i+1;j<loc.size();j++){
            if (loc[i]==loc[j]){
                shift=i;
                cyclel=j-i;
                done = true;
                break;
            }
        }
        if (done) break;
    }
    if (K<=shift){
        cout << loc[shift]+1;
    }else{
        K-=shift;
        K%=cyclel;
        if (K==0) K=cyclel-1;
        else K--;
        cout << loc[K+shift+1]+1;
    }
}