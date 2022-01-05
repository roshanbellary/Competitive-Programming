/*
Problem: Flowers
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_q
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
const int MN = 2e5;
ll N, h[MN], a[MN], dp[MN];
set<pair<ll,ll>> m;
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++) rv(h[i]);
    for (int i=0;i<N;i++) rv(a[i]);
    for (int i=0;i<N;i++){
        if (m.empty()) m.insert({h[i],a[i]});
        else{
            auto itr = m.upper_bound({h[i]+1,-1});
            if (itr==m.begin()){
                auto itr2 = itr;
                while (itr!=m.end()){
                    if (itr->s<=a[i]) itr++;
                    else break;
                }
                m.erase(itr2,itr);
                m.insert({h[i],a[i]});
            }else{
                itr--;ll v = itr->s+a[i];
                if (itr->f!=h[i]) itr++;
                auto itr2 = itr;
                while (itr!=m.end()){
                    if (itr->s<=v) itr++;
                    else break;
                }
                m.erase(itr2,itr);
                m.insert({h[i],v});
            }
        }
    }
    cout << m.rbegin()->s << "\n";
}
