/*
Problem: 
Problem Link: 
Notes: 
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
#define pb push_back
#define eb emplace_back
#define countbits __builtin_popcount
#define beg0 __builtin_clz
#define terminal0 __builtin_ctz
#define f first
#define s second
int mod=1e9+7;
inline void rv(int &n){
    n=0;int m=1;char c=getchar();if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar();if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){double p = 0.1;c=getchar();for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}}
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){double p = 0.1;c=getchar();for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}}
    n*=m;
}
inline void rv(string &w){w="";char c=getchar();while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar();}}
inline void rv(char &c){c=getchar();}
template<typename T, typename ...Types>
inline void rv(T &n, Types&&... args){rv(n);rv(args...);}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
const int MN = 1e5;
int N, M,v[MN], pred[MN];
vector<int> l[MN], order;
vector<vector<int>> ins;
bool cyc = 0, vis[MN];
priority_queue<int,vector<int>,greater<int>> pq;
void dfs(int ind, int t){
    v[ind]=t;
    for (int& j:l[ind]){
        if (v[j]==t){cyc=1;break;}
        else if (v[j]>0) continue;
        else dfs(j,t);
    }
}
bool checkcycle(int obv){
    cyc=0;
    for (int i=0;i<N;i++) l[i].clear(), v[i]=0;
    for (int i=0;i<=obv;i++){
        for (int j=0;j<ins[i].size()-1;j++){
            l[ins[i][j]].pb(ins[i][j+1]);
        }
    }
    int col = 1;
    for (int i=0;i<N;i++){
        if (v[i]==0) dfs(i,col++);
    }
    if (cyc) return 0;
    else return 1;
}
void construct(int e){
    for (int i=0;i<N;i++) l[i].clear();
    for (int i=0;i<N;i++) v[i]=0;
    for (int i=0;i<=e;i++) for (int j=0;j<ins[i].size()-1;j++) l[ins[i][j]].pb(ins[i][j+1]), pred[ins[i][j+1]]++;
    for (int i=0;i<N;i++){
        if (pred[i]==0) pq.push(i);
    }
    while (!pq.empty()){
        int ind = pq.top();pq.pop();
        order.pb(ind+1);
        for (int& j:l[ind]){pred[j]--;if (pred[j]==0) pq.push(j);}
    }
}
int main(){
	setIO("milkorder");cin >> N >> M;
    for (int i=0;i<M;i++){
        int n; cin >> n;ins.pb(vector<int>());
        while (n--){int v; cin >> v;v--;ins[ins.size()-1].eb(v);}
    }
    int s=0, f=M-1;
    while (s!=f){
        int mid=(s+f+1)/2;
        if (checkcycle(mid)) s=mid;
        else f=mid-1;
    }
    construct(s);
    for (int i=0;i<order.size()-1;i++){
        cout << order[i] << " ";
    }
    cout << order.back();
}
