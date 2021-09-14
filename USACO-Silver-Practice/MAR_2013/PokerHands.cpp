#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i=0;i<N;i++){
        cin >> v[i];
    }
    int max = v[0];
    long long count = 0;
    for (int i=1;i<N;i++){
        if (v[i]<max){
            count+=(max-v[i]);
        }
        max=v[i];
    }
    count+=max;
    cout << count << "\n";
}