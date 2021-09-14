#include <bits/stdc++.h>
#define int long long
using namespace std;
int K,N;
vector<int> v;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;v.resize(N);
    for (int i=0;i<N;i++) cin >> v[i];
    multiset<int> l;
    multiset<int> u;
    l.insert(v[0]);
    int bsum = v[0];
    int usum = 0;
    for (int i=1;i<K;i++){
        if (v[i]>*l.rbegin()){
            u.insert(v[i]);
            usum+=v[i];
        }else{
            l.insert(v[i]);
            bsum+=v[i];
        }
    }
    while (l.size()<(K+1)/2){
        l.insert(*u.begin());bsum+=*u.begin();usum-=(*u.begin());
        u.erase(u.begin());
    }
    while (l.size()>(K+1)/2){
        u.insert(*l.rbegin());bsum-=(*l.rbegin());usum+=(*l.rbegin());
        auto itr = l.end(); itr--;
        l.erase(itr);
    }
    cout << ((*l.rbegin())*l.size()-bsum)+(usum-(*l.rbegin())*u.size()) << " ";
    for (int i=K;i<N;i++){
        if (l.find(v[i-K])!=l.end()) l.erase(l.find(v[i-K])),bsum-=v[i-K];
        else u.erase(u.find(v[i-K])),usum-=v[i-K];
        while (l.size()<(K)/2){
            l.insert(*u.begin()); bsum+=(*u.begin());usum-=(*u.begin());
            u.erase(u.begin());
        }
        while (l.size()>(K)/2){
            u.insert(*l.rbegin());usum+=(*l.rbegin());
            auto itr = l.end(); itr--;bsum-=(*itr);
            l.erase(itr);
        }
        if (l.size()>0){
            if (v[i]>*l.rbegin()) u.insert(v[i]),usum+=v[i];
            else l.insert(v[i]),bsum+=v[i];
        }else l.insert(v[i]),bsum+=v[i];
        while (l.size()<(K+1)/2){
            l.insert(*u.begin());bsum+=(*u.begin());usum-=(*u.begin());
            u.erase(u.begin());
        }
        while (l.size()>(K+1)/2){
            u.insert(*l.rbegin());usum+=(*l.rbegin());
            auto itr = l.end(); itr--;bsum-=(*itr);
            l.erase(itr);
        }
        cout << ((*l.rbegin())*l.size()-bsum)+(usum-(*l.rbegin())*u.size()) << " ";
    }
}