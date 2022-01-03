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
const int MN = 1e4;
int N, T, p[MN];
set<int> v;
vector<int> ord;
void dfs(int i){
    int val = -1;
    while (true){
        if (val!=(-1)){v.insert(val);ord.pb(val);}
        cout << "? " << i+1 << endl;cin >> val;val--;
        if (v.find(val)!=v.end()) break;
    }
}
void solve(){
    cin >> N;for (int i=0;i<N;i++) p[i]=-1;
    for (int i=0;i<N;i++){
        if (p[i]<0){
            v.clear();ord.clear();dfs(i);
            if (ord.size()==1){
                p[i]=i;
            }else{
                int ind;
                for (int j=0;j<ord.size();j++){
                    if (ord[j]==i){ind=j;break;}
                }
                int si = ord.size(), pi=i;
                while (si--){
                    ind++;ind%=(ord.size());
                    p[pi]=ord[ind];pi=ord[ind];
                }
            }
        }
    }
    cout << "! ";
    for (int i=0;i<N;i++) cout << p[i]+1 << " ";
    cout << endl;
}
int main(){
	setIO();cin >> T;
    while (T--) solve();
}
