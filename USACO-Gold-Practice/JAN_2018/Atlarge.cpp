#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<vector<int>> l;
int main(){
    freopen("atlarge.in","r",stdin);
    freopen("atlarge.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K; K--;
    for (int i=0;i<N;i++) l.push_back(vector<int>());
    for (int i=0;i<N-1;i++){
        int s,f;
        cin >> s >> f; s--;f--;
        l[s].push_back(f);
        l[f].push_back(s);
    }
    vector<int> dk(N,-1);
    queue<int> q;
    dk[K]=0;
    q.push(K);
    while (!q.empty()){
        int i = q.front();
        q.pop();
        for (int a:l[i]){
            if (dk[a]<0){
                dk[a]=dk[i]+1;
                q.push(a);
            }
        }
    }
    vector<int> ones;
    for (int i=0;i<N;i++){
        if (l[i].size()==1) ones.push_back(i);
    }
    vector<bool> v(N,false);
    vector<int> de(N,-1);
    queue<int> q2;
    for (int i=0;i<ones.size();i++){
        de[ones[i]]=0;
        q2.push(ones[i]);
    }
    while (!q2.empty()){
        int i = q2.front();
        q2.pop();
        for (int j:l[i]){
            if (de[j]<0){
                de[j]=de[i]+1;
                q2.push(j);
            }else if (de[j]>de[i]+1){
                de[j]=de[i]+1;
            }
        }
    }
    int count = 0;
    queue<int> q3;
    q3.push(K);
    vector<bool> v2(N,false);
    while (!q3.empty()){
        int i = q3.front();
        q3.pop();
        if (v2[i]) continue;
        else v2[i]=true;
        for (int j:l[i]){
            if (dk[j]<=de[j]){
                q3.push(j);
            }else{
                count++;
            }
        }
    }
    cout << count << "\n";
}