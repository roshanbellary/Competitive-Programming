#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define int long long
#define ll long long
#define pb push_back
#define eb emplace_back
#define countbits __builtin_popcount
#define beg0 __builtin_clz
#define terminal0 __builtin_ctz
#define f first
#define s second
int mod=1e9+7;
template <class T> 
void rn(T &n){
    n=0;int m = 1;int c;
    c = getchar();if (c=='-') m=-1;
    for (;c>47 && c<58;c=getchar()){
        n=n*(1<<1)+n*(1<<3)+c-48;
    }
    n*=m;
}
void rw(string &w){
    w="";char c=getchar();
    while (c!=' '&&c!='\n'&&c!=EOF){
        w+=c;c=getchar();
    }
}
void rc(char &c){
	c=getchar();
}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
ll N, M,d[(int)1e5];
vector<pair<int,ll>> l[(int)1e5];
int32_t main(){
	setIO();cin >> N >> M;
    for (int i=0;i<N;i++) d[i]=1e18;
    for (int i=0;i<M;i++){
        int u,v,c; cin >> u >> v >> c;
        l[--u].pb({--v,c});
    }
    priority_queue<pair<ll,int>> pq;
    pq.push({0,0});d[0]=0;
    while (!pq.empty()){
        pair<ll,int> a = pq.top();pq.pop();a.f*=(-1);
        if (a.f>d[a.s]) continue;
        for (pair<int,ll> j:l[a.s]){
            if (a.f+j.s<d[j.f]){
                d[j.f]=a.f+j.s;
                pq.push({-(a.f+j.s),j.f});
            }
        }
    }
    for (int i=0;i<N;i++){
        cout << d[i] << " ";
    }
    cout << "\n";
} 
