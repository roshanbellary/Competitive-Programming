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
int T, N, b[(int)2e5],p[(int)2e5],e[(int)2e5],R;
vector<int> l[(int)2e5];
void dfs(int ind){
    for (int j:l[ind]){
        e[j]=p[j]-p[ind];
        dfs(j);
    }
}
int main(){
	setIO();cin >> T;
    while (T--){
        cin >> N;for (int i=0;i<N;i++) l[i].clear();
        for (int i=0;i<N;i++){cin >> b[i];if (--b[i]!=i) l[b[i]].pb(i);}
        for (int i=0;i<N;i++){int n; cin >> n;p[--n]=i;}
        for (int i=0;i<N;i++) if (b[i]==i) R=i;
        dfs(R);e[R]=0;bool w = true;
        for (int i=0;i<N;i++){
            if (e[i]<0){
                cout << "-1\n";w=false;
                break;
            }
        }
        if (!w) continue;
        for (int i=0;i<N;i++){
            cout << e[i] << " ";
        }
        cout << "\n";
    }
}
