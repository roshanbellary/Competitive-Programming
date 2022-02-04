/*
Problem: Searching For Soulmates
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=1182
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
ll N, A, B;
void filla(vector<pair<ll,ll>> &v, ll a){
    ll C = a, d = 0;
    while (C>1){
        v.insert(v.begin(), {C,d});
        if (C%2==1) d+=2, C=(C+1)/2;
        else d++,C/=2;
    }
    v.insert(v.begin(),{C,d});
    C=a;d=1;
    while (2*C<=1e18){
        v.pb({2*C,d});C*=2;d++;
    }
}
void fillb(vector<pair<ll,ll>> &v, ll a){
    ll C = a, d = 0;
    while (C>0){
        v.insert(v.begin(), {C,d});
        if (C%2==1) d+=2, C=(C-1)/2;
        else d++,C/=2;
    }
    C=a;d=1;
    while (2*C<=1e18){
        v.pb({2*C,d});C*=2;d++;
    }
}
void solve(){
    rv(A,B);vector<pair<ll,ll>> da, db;
    filla(da,A);fillb(db,B);
    ll minv = 1e18;
    for (auto& a:da){
        for (auto& b:db){
            if (a.f>b.f) continue;
            minv=min(a.s+b.s+abs(b.f-a.f),minv);
        }
    }
    cout << minv << "\n";
}
int main(){
	setIO();rv(N);
    while (N--) solve();
}
