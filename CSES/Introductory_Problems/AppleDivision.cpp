#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> p;
vector<bool> chosen;
ll sum1 = 0;
ll sum = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        sum+=store;
        p.push_back(store);
    }
    ll minimum = 1e9;
    for (int i=0;i<(1<<N);i++){
        sum1 = 0;
        for (int j=0;j<N;j++){
            if (i&(1<<j)){
                sum1+=p[j];
            }
        }
        if (minimum>abs(sum-2*sum1)) minimum=abs(sum-2*sum1);
    }
    cout << minimum;
}