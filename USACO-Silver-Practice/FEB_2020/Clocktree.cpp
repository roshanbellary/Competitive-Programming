#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> clocks;
vector<vector<int> > e;
int sums = 0;
void dfs(int i, int prev, int dist){
    sums+=(clocks[i]*pow(-1,dist));
    for (auto j: e[i]){
        if (j!=prev){
            dfs(j,i,dist+1);
        }
    }
}
int main(){
    freopen("clocktree.in","r",stdin);
    freopen("clocktree.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        clocks.push_back(store);
        e.push_back(vector<int>());
    }
    for (int i=0;i<N-1;i++){
        int a, b;
        cin >> a >> b;
        e[a-1].push_back(b-1);
        e[b-1].push_back(a-1);
    }
    int count = 0;
    for (int i=0;i<N;i++){
        sums = 0;
        dfs(i,i,0);
        if ((sums%12==1)||(sums%12==0)||(sums%12==-11)){
            count++;
        }
    }
    cout << count;
}