#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    set<int> s;
    int N;
    cin >> N;
    int maximum = 0;
    vector<pair<int,int> > pairs;
    int v[N];
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        v[i]=store;
        pairs.push_back(pair<int,int>(store,i));
    }
    sort(pairs.begin(),pairs.end());
    int length = 0;
    for (int i=0;i<N;i++){
        int a = 0;
        int b = N-1;
        while (a!=b){
            int mid = (a+b+1)/2;
            if (pairs[mid]<=pair<int,int>(v[i],i)){
                a=mid;
            }else{
                b=mid-1;
            }
        }
        if (a==0){
            length++;
        }else{
            if (pairs[a-1].first==pairs[a].first){
                length=min(pairs[a].second-pairs[a-1].second,length+1);
            }else{
                length++;
            }
        }
        maximum=max(length,maximum);
    }
    cout << maximum << "\n";
}