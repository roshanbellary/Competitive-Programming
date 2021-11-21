/*
Problem: ABC Conjecture
Problem Link: https://atcoder.jp/contests/abc227/tasks/abc227_c
Notes: Hard in terms of proving algorithmic correctness. It took me a while to realize that my solution 
would be able to run in time in O(N^(2/3)). The main realization here is that we can find an upper bound on the runtime as
the number of C's is a monotonically decreasing function.
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
ll N;
int main(){
	setIO();cin >> N;
	ll res = 0;
	for (ll i=1;i*i*i<=N;i++){
		for (ll j=i;j*j*i<=N;j++){
			res+=((N/i)/j-j+1);
		}
	}
	cout << res << "\n";
}
