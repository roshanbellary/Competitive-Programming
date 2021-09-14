#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> l;
int32_t main(){
    freopen("piggyback.in","r",stdin);
    freopen("piggyback.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int B,E,P,N,M;
    cin >> B >> E >> P >> N >> M;
    for (int i=0;i<N;i++){
        l.push_back(vector<int>());
    }
    for (int i=0;i<M;i++){
        int f,s;
        cin >> f >> s; f--;s--;
        l[f].push_back(s);
        l[s].push_back(f);
    }
    vector<int> b(N,-1);
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    while (!q.empty()){
        int i = q.front().first;
        int d = q.front().second;
        q.pop();
        b[i]=d;
        for (int n:l[i]){
            if (b[n]<0){
                b[n]=d+1;
                q.push(make_pair(n,d+1));
            }
        }
    }
    vector<int> e(N,-1);
    q.push(make_pair(1,0));
    while (!q.empty()){
        int i = q.front().first;
        int d = q.front().second;
        q.pop();
        e[i]=d;
        for (int n:l[i]){
            if (e[n]<0){
                e[n]=d+1;
                q.push(make_pair(n,d+1));
            }
        }
    }
    vector<int> d(N,-1);
    q.push(make_pair(N-1,0));
    while (!q.empty()){
        int i = q.front().first;
        int de = q.front().second;
        q.pop();
        d[i]=de;
        for (int n:l[i]){
            if (d[n]<0){
                d[n]=de+1;
                q.push(make_pair(n,de+1));
            }
        }
    }
    int totmin = 1e18;
    int diff;
    if (B+E<P) diff=B+E;
    else diff=P;
    for (int i=0;i<N;i++){
        int mini = B*b[i]+E*e[i]+diff*d[i];
        if (totmin>mini){
            totmin=mini;
        }
    }
    if (totmin>B*d[0]+E*d[1]){
        totmin=B*d[0]+E*d[1];
    }
    cout << totmin << "\n";
}