/*
Problem: Cow Frisbee
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=1183
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
const int MN = 3e5+1;
ll N, h[MN], rev[MN], ft1[MN], ft2[MN], R=0;
void update1(int i, ll v){
    while (i<MN){
        ft1[i]+=v;
        i+=(i&(-i));
    }
}
ll query1(int i){return (i?ft1[i]+query1(i-(i&(-i))):ft1[0]);}
void update2(int i, int v){
    while (i<MN){
        ft2[i]+=v;
        i+=(i&(-i));
    }
}
ll query2(int i){return (i?ft2[i]+query2(i-(i&(-i))):ft2[i]);}
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++) rv(h[i]), rev[h[i]]=i;
    set<int> m;
    for (ll i=0;i<N;i++){
        auto itr = m.upper_bound(h[i]);
        if (itr==m.end()) R+=query2(MN-1)*(i+1)-query1(MN-1); 
        else R+=((query2(*itr))*(i+1)-query1(*itr));
        itr = m.begin();
        while (itr!=m.end()){
            if (*itr<h[i]){
                update1(*itr,-rev[*itr]);
                update2(*itr,-1);
                itr++;
            }else break;
        }
        m.erase(m.begin(),itr);
        update1(h[i],i);update2(h[i],1);
        m.insert(h[i]);
    }
    cout << R << "\n";
}
