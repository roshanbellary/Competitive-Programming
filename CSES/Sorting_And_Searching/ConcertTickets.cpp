#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N, M;
    cin >> N >> M;
    multiset<int> h;
    vector<int> t(M);
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        h.insert(store);
    }
    vector<bool> u(N, false);
    for (int i=0;i<M;i++)
        cin >> t[i];
    int temp = -1;
    for (int i=0;i<M;i++){
        if (h.size()==0){
            temp=i;
            break;
        }
        multiset<int>::iterator itr = h.lower_bound(t[i]);
        if (itr==h.end()){
            itr--;
            cout << *itr << "\n";
            h.erase(itr);
            continue;
        }
        int value = *itr;
        if (value<=t[i]){
            cout << value << "\n";
            h.erase(itr);
        }else{
            if (itr==h.begin()){
                cout << -1 << "\n";
            }else{
                itr--;
                cout << *itr << "\n";
                h.erase(itr);
            }
        }
    }
    if (temp>0){
        for (int i=temp;i<M;i++){
            cout << "-1\n";
        }
    }
}