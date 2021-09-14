#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> g;
int main(){
    freopen("homework.in","r",stdin);
    freopen("homework.out","w",stdout);
    cin >> N;
    long dp[N];
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        g.push_back(store);
    }
    long m[N];
    long minimum = 10001;
    for (int i=N-1;i>=0;i--){
        if (g[i]<minimum){
            minimum=g[i];
        }
        m[i]=minimum;
        if (i==N-1){
            dp[i]=g[i];
        }else{
            dp[i]=dp[i+1]+g[i];
        }
    }
    long max = -1;
    long num = 1;
    vector<long> v;
    for (int i=1;i<N-1;i++){
        long res = dp[i]-m[i];
        if (res*num>max*(N-i-1)){
            num=(N-i-1);
            max=res;
            v.clear();
            v.push_back(i);
        }else if (res*num==max*(N-i-1)){
            num=(N-i-1);
            max=res;
            v.push_back(i);
        }
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++){
        if (i==v.size()-1){
            cout << v[i];
        }else{
            cout << v[i] << endl;
        }
    }
}