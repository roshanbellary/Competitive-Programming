#include <bits/stdc++.h>
using namespace std;
int K,N;
vector<int> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;v.resize(N);
    for (int i=0;i<N;i++) cin >> v[i];
    multiset<int> l;
    multiset<int> u;
    l.insert(v[0]);
    for (int i=1;i<K;i++){
        if (v[i]>*l.rbegin()){
            u.insert(v[i]);
        }else{
            l.insert(v[i]);
        }
    }
    while (l.size()<(K+1)/2){
        l.insert(*u.begin());
        u.erase(u.begin());
    }
    while (l.size()>(K+1)/2){
        u.insert(*l.rbegin());
        auto itr = l.end(); itr--;
        l.erase(itr);
    }
    cout << *l.rbegin() << " ";
    for (int i=K;i<N;i++){
        if (l.find(v[i-K])!=l.end()) l.erase(l.find(v[i-K]));
        else u.erase(u.find(v[i-K]));
        while (l.size()<(K)/2){
            l.insert(*u.begin());
            u.erase(u.begin());
        }
        while (l.size()>(K)/2){
            u.insert(*l.rbegin());
            auto itr = l.end(); itr--;
            l.erase(itr);
        }
        if (l.size()>0){
            if (v[i]>*l.rbegin()) u.insert(v[i]);
            else l.insert(v[i]);
        }else l.insert(v[i]);
        while (l.size()<(K+1)/2){
            l.insert(*u.begin());
            u.erase(u.begin());
        }
        while (l.size()>(K+1)/2){
            u.insert(*l.rbegin());
            auto itr = l.end(); itr--;
            l.erase(itr);
        }
        cout << *l.rbegin() << " ";
    }
}