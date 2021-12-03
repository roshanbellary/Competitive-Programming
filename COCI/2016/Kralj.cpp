/*
Problem: COCI 2016/2017 Round #1 Problem 5 Kralj
Problem Link: https://oj.uz/problem/view/COCI16_kralj
Notes: Determining where to start moving around the circle was the hard part of this problem but 
I was able to figure out this position by iterating about when the elves are distributed off 
till they reach 1.
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
const int MN = 5e5;
int N,a[MN], p[MN], v[MN];
vector<int> l[MN];
multiset<int> str;
bool c[MN];
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++) rv(a[i]),a[i]--;
    for (int i=0;i<N;i++) rv(p[i]);
    for (int i=0;i<N;i++) rv(v[i]);
    for (int i=0;i<N;i++) l[a[i]].pb(v[i]);
    int ind = 0, d=N, sind = -1, mv = 1e9, col = 0;
    while (d--){
        col+=(l[ind].size()-1);
        if (col<mv){
            mv=col,ind=col;
        }
        ind++;
    }
    d=N+1;ind = (sind+1)%N;int games = 0;
    while (d--){
        for (int j:l[ind]) str.insert(j);
        l[ind].clear();
        if (str.size()>0){
            auto itr = str.upper_bound(p[ind]);
            if (itr==str.end()) str.erase(str.begin());
            else{
                games++;str.erase(itr);
            }
        }
        ind++;ind%=N;
    }
    cout << games << "\n";
}
