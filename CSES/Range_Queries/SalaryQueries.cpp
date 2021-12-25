/*
Problem: Salary Queries
Problem Link: https://cses.fi/problemset/task/1144/
Notes: 
Dumbass problem(on my part). Using coordinate compression and a fenwick tree you can solve it
but you shouldn't use a map for the coordinate compression. Another sol is to use an indexed set yet my indexed
set sol kept failing
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less_equal<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
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
struct Query{string t; ll a, b;};
const int MN = 2e5;
const int MC = 6e5+1;
ll N, Q, v[MN], ft[MC];
Query q[MN];
vector<ll> store, dup;
inline void update(ll ind, ll c){while (ind<=MC-1){ft[ind]+=c;ind+=(ind&(-ind));}}
inline ll query(ll ind){return (ind?ft[ind]+query(ind-(ind&(-ind))):0);}
inline void push(ll n){
    string s = to_string(n);
    for (char c:s) putchar(c);
    putchar('\n');
}
inline ll find(ll v){
    ll l = 0, r = dup.size()-1;
    while (l!=r){
        ll mid = (l+r+1)/2;
        if (dup[mid]<=v) l=mid;
        else r=mid-1;
    }
    return (l+1);
}
int main(){
	setIO();rv(N, Q);
    for (ll i=0;i<N;i++) rv(v[i]),store.pb(v[i]);
    for (ll i=0;i<Q;i++){rv(q[i].t,q[i].a,q[i].b);if (q[i].t=="!") store.pb(q[i].b); else store.pb(q[i].a),store.pb(q[i].b);}
    sort(store.begin(),store.end());
    for (ll i=0;i<store.size();i++){
        ll j=i+1;
        while (j<store.size()){
            if (store[j]==store[i]) j++;
            else break;
        }
        dup.pb(store[i]);i=j-1;
    }
    for (ll i=0;i<N;i++) update(find(v[i]),1);
    for (ll i=0;i<Q;i++){
        if (q[i].t=="!"){q[i].b=find(q[i].b);update(v[--q[i].a],-1);update(q[i].b,1);v[q[i].a]=q[i].b;}
        else cout << query(find(q[i].b))-query(find(q[i].a)-1) << "\n";
    }
}