#include <bits/stdc++.h>
using namespace std;
vector<int> ft;
void update(int i, int v){
    while (i<=ft.size()){
        ft[i]+=v;
        i+=(i&(-i));
    }
}
int query(int x){
    return x>0 ? ft[x]+query(x-(x&(-x))):0;
}
int main(){
    freopen("bphoto.in","r",stdin);
    freopen("bphoto.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> v(N);
    vector<int> st(N);
    for (int i=0;i<N;i++){
        cin >> v[i];
        st[i]=v[i];
    }
    sort(st.begin(),st.end());
    map<int,int> m;
    int count = 1;
    for (int i=N-1;i>=0;i--){
        int j = i-1;
        m[st[i]]=count;
        while (j>=0){
            if (st[j]!=st[i]){
                count++;
                break;
            }else{
                j--;
            }
        }
        i=j+1;
    }
    for (int i=0;i<count;i++){
        ft.push_back(0);
    }
    for (int i=0;i<N;i++){
        v[i]=m[v[i]];
    }
    int l[N+1];
    for (int i=1;i<N+1;i++){
        l[i]=query(v[i-1]-1);
        update(v[i-1],1);
    }
    fill(ft.begin(),ft.end(),0);
    reverse(v.begin(),v.end());
    int r[N+1];
    for (int i=1;i<N+1;i++){
        r[N+1-i]=query(v[i-1]-1);
        update(v[i-1],1);
    }
    count = 0;
    for (int i=1;i<N+1;i++){
        int maxi = max(l[i],r[i]);
        int mini = min(l[i],r[i]);
        if (maxi>2*mini) count++;
    }
    cout << count << "\n";
}