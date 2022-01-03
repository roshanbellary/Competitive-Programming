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
struct Seg{ll s, f, c;};
int T, N;
void solve(){
    rv(N);vector<Seg> n;
    for (int i=0;i<N;i++){
        Seg a; rv(a.s,a.f,a.c);
        n.pb(a);
    }
    ll l=1e9, r=0, rcol = 1e9, lcol=1e9, col=1e18;
    bool dub = 0;
    for (int i=0;i<N;i++){
        if (n[i].s<=l && n[i].f>=r){
            if (n[i].s==l && n[i].f==r){
                rcol=min(rcol,n[i].c);lcol=min(lcol,n[i].c);
                col=min(col,n[i].c);
            }else if (n[i].s==l || n[i].f==r){
                col=n[i].c;l=min(n[i].s,l);r=max(n[i].f,r);
                if (l>n[i].s) lcol=n[i].c;
                else lcol=min(lcol,n[i].c);
                if (r<n[i].f) rcol=n[i].c;
                else rcol=min(rcol,n[i].c);
            }else{
                col=n[i].c;rcol=n[i].c;lcol=n[i].c;
                l=min(n[i].s,l);r=max(n[i].f,r);
            }
        }else if (n[i].s<=l){
            if (n[i].s==l){
                lcol=min(lcol,n[i].c);
            }else{
                l==n[i].s;lcol=n[i].c;col=1e18;
            }
        }else if (n[i].f>=r){
            if (n[i].f==r){
                rcol=min(rcol,n[i].c);
            }else{
                r=n[i].f;rcol=n[i].c;col=1e18;
            }
        }
        col=min(col,lcol+rcol);
        cout << col << "\n";
    }
}
int main(){
	setIO();rv(T);
    while (T--) solve();
}
