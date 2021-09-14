#include <bits/stdc++.h>
#define ll long long
using namespace std;
string w;
set<string> d;
vector<bool> chosen;
vector<char> permute;
ll factorial(int n){
    ll result = 1;
    for (int i=2;i<=n;i++){
        result*=i;
    }
    return result;
}
void permutation(){
    if (permute.size()==w.length()){
        string store = "";
        for (int i=0;i<permute.size();i++){
            store+=permute[i];
        }
        d.insert(store);
    }else{
        for (int i=0;i<w.length();i++){
            if (!chosen[i]){
                chosen[i]=true;
                permute.push_back(w[i]);
                permutation();
                permute.pop_back();
                chosen[i]=false;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> w;
    int c[26];
    fill(c,c+26,0);
    for (int i=0;i<w.length();i++){
        c[w[i]-'A']++;
        chosen.push_back(false);
    }
    permutation();
    cout << d.size() << endl;
    for (string s:d){
        cout << s << endl;
    }
}