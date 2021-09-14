#include <bits/stdc++.h>
using namespace std;
vector<int> t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, D; cin >> N >> D;
    for (int i=0;i<N;i++){
        int store; cin >> store;
        t.push_back(store);
    }
    sort(t.begin(),t.end());
    int count = 0;
    int time = 0;
    bool w = true;
    for (int i=0;i<t.size();i++){
        if (time+t[i]<=D) time+=t[i];
        else{
            w=false;
            break;
        }
        if (time+10<=D) count+=2, time+=10;
        else if (time+5<=D){
            count++;
            time+=5;
            w=(i==t.size()-1);
            break;
        }else{
            w=(i==t.size()-1);
            break;
        }
    }
    if (w){
        count+=(D-time)/5;
        cout << count << "\n";
    }else cout << "-1\n";
}