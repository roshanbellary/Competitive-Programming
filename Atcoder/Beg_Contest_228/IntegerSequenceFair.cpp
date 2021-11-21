/*
Problem: Integer Sequence Fair
Problem Link:https://atcoder.jp/contests/abc228/tasks/abc228_e 
Notes: 
The solution is M^K^N as there are K^N unique sequences and there are
M values to choose from for each sequence. Now we have to take this mod 998244353.
By Euler's theorem and totient function since 998244353 is prime then any number excluding ones divisible by
998244353 when raised to 998244353-1=998244352 will be congruent to 1. For numbers that are divisible by 998244353 we instantly 
knew that the result would be 0. So using fast modular exponentiation we can get the power M needs to be raised to and doing
fast modular exponentiation again we get our result. (Took me way too long to realize the edge case of numbers divisible by 998244353 evaluating to 0).
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
ll mod=998244353;
template <class T> 
void rn(T &n){
    n=0;int m = 1;int c;
    c = getchar();if (c=='-') m=-1;
    for (;c>47 && c<58;c=getchar()){
        n=n*(1<<1)+n*(1<<3)+c-48;
    }
    n*=m;
}
void rw(string &w){
    w="";char c=getchar();
    while (c!=' '&&c!='\n'&&c!=EOF){
        w+=c;c=getchar();
    }
}
void rc(char &c){
	c=getchar();
}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
ll N, K, M;
ll modpow(ll n, ll p, ll m){
    if (p==0) return 1;
    if (p%2==0){
        ll res = modpow(n,p/2,m)%m;
        return ((res*res)%m);
    }else{
        ll res = modpow(n,p/2,m)%m;
        return (((res*res)%m)*n)%m;
    }
}
int main(){
	setIO();rn(N);rn(K);rn(M);
    M%=mod;K%=(mod-1);
    if (M==0){cout << "0\n";return 0;}
    ll P = modpow(K,N,mod-1)%(mod-1);
    cout << modpow(M,P,mod)%mod << "\n";
}
