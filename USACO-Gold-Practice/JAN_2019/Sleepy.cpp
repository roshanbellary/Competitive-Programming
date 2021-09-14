#include <bits/stdc++.h>
using namespace std;
vector<int> ft;
void update(int i, int v){
    while (i<=ft.size()){
        ft[i]+=v;
        i+=(i&(-i));
    }
}
int query(int i){
    return (i>0) ? ft[i]+query(i-(i&(-i))):0;
}
int main(){
    freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> o(N);
    for (int i=0;i<N;i++)
        cin >> o[i];
    int ei = -1;
    for (int i=N-1;i>=1;i--){
        if (o[i-1]>=o[i]){
            ei=(i);
            break;
        }
    }
    if (ei<0) ei=0;
    for (int i=0;i<N+1;i++){
        ft.push_back(0);
    }
    for (int i=ei;i<N;i++){
        update(o[i],1);
    }
    int result[N];
    memset(result,0,sizeof(result));
    for (int i=0;i<ei;i++){
        result[i]=(ei-i-1)+query(o[i]);
        update(o[i],1);
    }
    cout << ei << "\n";
    for (int i=0;i<ei-1;i++){
        cout << result[i] << " ";
    }
    if (ei>0) cout << result[ei-1];
}