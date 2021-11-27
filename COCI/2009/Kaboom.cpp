/*
Problem: CENTRAL EUROPEAN OLYMPIAD IN INFORMATICS 2009 Kaboom
Problem Link: https://wcipeg.com/problem/coci094p5
Notes: Really hard dp problem. Made my transitions around the spirals that can be formed
It took me a while to figure out the recursion of making the spirals on either side of the 
stick and  checking to see if they intersect or not.
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
int mod=10301;
inline void rv(int &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar();
        for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar();
        for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(string &w){
    w="";char c=getchar();
    while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar();}
}
inline void rv(char &c){c=getchar();}
template<typename T, typename ...Types>
void rv(T &n, Types&&... args){rv(n);rv(args...);}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N, A, B;
ll dpa[1000][1000][2],dpb[1000][1000][2];
int ma(int n, int sp, bool t){
    ll res  = dpa[n][sp][t];
    if (res!=(-1)) return res;
    res=t;
    if (sp<=n) res+=ma(n-sp,sp,1);
    if (n!=0) res+=ma(n-1,sp+1,0);
    res%=mod;return res;
}
int mb(int n, int sp, bool t){
    ll res = dpb[n][sp][t];
    if (res!=-1) return res;
    res = 0;
    if (t) res+=ma(n,B,1);
    if (sp<=n) res+=mb(n-sp,sp,1);
    if (n) res+=mb(n-1,sp+1,0); 
    res%=mod;return res;
}
int main(){
    setIO();
    for (int i=0;i<1000;i++) for (int j=0;j<1000;j++) for (int k=0;k<2;k++) dpa[i][j][k]=-1;
    for (int i=0;i<1000;i++) for (int j=0;j<1000;j++) for (int k=0;k<2;k++) dpb[i][j][k]=-1;
	rv(N, A, B);
    cout << mb(N-A-B,B,1) << "\n"; 
}
