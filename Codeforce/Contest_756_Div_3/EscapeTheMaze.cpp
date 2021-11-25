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
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int T, N, K, x[(int)2e5],df[(int)2e5], dy[(int)2e5];
vector<int> l[(int)2e5];
void dfs(int ind, int d){
    dy[ind]=d++;
    for (int j:l[ind]){
        if (dy[j]>d) dfs(j,d);
    }
}
int main(){
	setIO();cin >> T;
    while (T--){
        cin >> N >> K;
        for (int i=0;i<N;i++){
            df[i]=1e9;dy[i]=1e9;
        }
        for (int i=0;i<K;i++) cin >> x[i],x[i]--;
        for (int i=0;i<N;i++) l[i].clear();
        for (int i=0;i<N-1;i++){int u, v; cin >> u >> v; l[--u].pb(--v);l[v].pb(u);}
        dfs(0,0);
        queue<pair<int,int>> q;
        for (int i=0;i<K;i++){
            df[x[i]]=0;q.push({x[i],0});
        }
        while (!q.empty()){
            pair<int,int> e = q.front();q.pop();
            if (df[e.f]<e.s) continue;
            for (int j:l[e.f]){
                if (df[j]>e.s+1){
                    df[j]=e.s+1;q.push({j,e.s+1});
                }
            }
        }
        bool w = 0;
        for (int i=0;i<N;i++){
            if (l[i].size()==1 && i!=0){
                if (df[i]>dy[i]){
                    cout << "YES\n";w=1;
                    break;
                }
            }
        }
        if (!w) cout << "NO\n";
    }
}
