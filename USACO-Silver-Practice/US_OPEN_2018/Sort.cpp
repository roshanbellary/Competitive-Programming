#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int,int> > v;
int main(){
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        v.push_back(pair<int,int>(store,i));
    }
    sort(v.begin(),v.end());
    int swaps = 0;
    for (int i=0;i<N;i++){
        swaps=max(abs(i-v[i].second),swaps);
    }
    cout << swaps+1;
}