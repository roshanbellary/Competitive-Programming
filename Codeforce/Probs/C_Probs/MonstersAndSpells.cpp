/*
Problem: Monsters and Spells
Problem Link: https://codeforces.com/contest/1626/problem/C
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
inline void rv(char &c){c=' ';while (c==' '|| c=='\n' || c==EOF) c=getchar();}
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
struct Event{
    int t, ty;
    bool operator<(const Event &a) const{
        if (t==a.t) return (ty<a.ty);
        return (t<a.t);
    }
};
const int MN = 100;
int T, N, h[MN], k[MN];
void solve(){
    rv(N);
    for (int i=0;i<N;i++) rv(k[i]);
    for (int i=0;i<N;i++) rv(h[i]);
    vector<Event> sp;
    for (int i=0;i<N;i++) sp.pb({k[i]-h[i],1}), sp.pb({k[i],-1});
    sort(sp.begin(),sp.end());
    ll cm = 1, ct=0, act = 0,col = 0;
    for (int i=0;i<sp.size();i++){
        if (act>0) col+=(cm*(sp[i].t-ct)+((sp[i].t-ct-1)*(sp[i].t-ct))/2), cm+=(sp[i].t-ct);
        ct=sp[i].t;act+=sp[i].ty;
        if (act==0) cm=1;
    }
    cout << col << "\n";
}
int main(){
	setIO();rv(T);
    while (T--) solve();
}
