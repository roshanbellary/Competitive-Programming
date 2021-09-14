#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<pair<int,int>> d;
    int ls = 0;
    int rs = 0;
    int lo = 0;
    int ro = 0;
    for (int i=0;i<N;i++){
        int r,l; cin >> r >> l;
        d.push_back(make_pair(r,l));
        ls+=r; rs+=l;
        if ((r%2==1)&&(l%2==0)) lo++;
        if ((r%2==0)&&(l%2==1)) ro++;
    }
    if ((ls+rs)%2==0){
        if (ls%2==1){
            if ((ro>0)||(lo>0)) cout << "1\n";
            else cout << "-1\n";
        }else{
            cout << "0\n";
        }
    }else{
        cout << "-1\n";
    }
}