#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> n;
int main(){
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    cin >> N >> K;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        n.push_back(store);
    }
    sort(n.begin(),n.end());
    vector<pair<int,int> > g;
    for (int i=0;i<N;i++){
        int lim = n[i]+K;
        int a=i;
        int b=N-1;
        while (a!=b){
            int mid = (a+b+1)/2;
            if (n[mid]<=lim){
                a=mid;
            }else{
                b=mid-1;
            }
        }
        g.push_back(pair<int,int>(i,a));
    }
    int maximum = 0;
    for (int i=0;i<N;i++){
        int a = g[i].second;
        for (int j=a+1;j<N;j++){
            maximum=max(maximum,a-i+1+g[j].second-j+1);
        }
    }
    cout << maximum;
}