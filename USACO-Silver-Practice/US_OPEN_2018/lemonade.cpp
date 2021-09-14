#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> w;
int main(){
    freopen("lemonade.in","r",stdin);
    freopen("lemonade.out","w",stdout);
    int N;
    cin >> N;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        w.push_back(store);
    }
    sort(w.begin(),w.end());
    int num=0;
    for (int i=N-1;i>=0;i--){
        if (w[i]>=num){
            num++;
        }
    }
    cout << num;
}