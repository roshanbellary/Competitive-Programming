#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int N;
vector<int> s;
vector<int> f;
vector<bool> t;
map<int,int> m;
int counts=0;
void move(int i, int init){
    if (i==init) return;
    else {counts++;t[i]=true;move(m[i],init);}
}
int main(){
    freopen("reorder.in","r",stdin);
    freopen("reorder.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        s.push_back(store);
        t.push_back(false);
    }
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        f.push_back(store);
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (s[i]==f[j]){
                if (i==j) t[i]=true;
                else m[i]=j;
                break;
            }
        }
    }
    int maximum=0;
    int shifts=0;
    for (int i=0;i<N;i++){
        if (!t[i]){
            shifts++;
            counts=1;
            t[i]=true;
            move(m[i],i);
            maximum=max(counts,maximum);
        }
    }
    if (shifts==0) cout << shifts << " " << -1;
    else cout << shifts << " " << maximum;
}