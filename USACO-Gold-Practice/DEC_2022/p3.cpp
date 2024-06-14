#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MN = 1e5, MM = 2e5;
ll N, M, par[MN], s[MN], res=0, mf[MN];
pair<int,int> fr[MN];
set<ll> l[MN];
int findparent(int i){
    if (i==par[i]) return i;
    else{
        par[i]=findparent(par[i]);
        return par[i];
    }
}
void unions(int i, int j){
    i=findparent(i);j=findparent(j);
    if (i==j) return;
    if (s[j]>s[i]) swap(i,j);
    par[j]=i;s[i]+=s[j];
}
bool iteration(){
    for (int i=0;i<N;i++){
        fr[i].first=l[i].size();fr[i].second=i;
        par[i]=i;s[i]=1;
    }
    sort(fr,fr+N,greater<pair<int,int>>());
    for (int i=0;i<N;i++){
        for (ll j:l[fr[i].second]){
            if (l[j].size()>=l[fr[i].second].size()) unions(j,fr[i].second);
        }
    }
    for (int i=0;i<N;i++) mf[i]=l[i].size();
    for (int i=0;i<N;i++) mf[findparent(i)]=min(mf[findparent(i)],mf[i]);
    for (int i=0;i<N;i++){
        cout << mf[i] << " " << s[i] << " " << findparent(i) << "a\n";
    }
    ll resl = 0;
    for (int i=0;i<N;i++) resl=max(resl, mf[findparent(i)]*s[i]);
    if (res<resl){
        res=resl;return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> M;
    for (int i=0;i<M;i++){
        int a, b; cin >> a >> b;
        l[--a].insert(--b);
        l[b].insert(a);
    }
    while (iteration()){
        cout << res << "\n";
        for (int i=0;i<N;i++){
            vector<ll> store;
            for (ll j:l[i]) if (findparent(j)!=findparent(i)) fr[i].first--, store.push_back(j);
            for (ll a:store) l[i].erase(a), l[a].erase(i);
        }
    }
    cout << res << "\n";
}