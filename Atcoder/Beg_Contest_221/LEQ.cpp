/*
Problem: LEQ
Problem Link: https://atcoder.jp/contests/abc221/tasks/abc221_e
Notes: Cool application of Fenwick Trees and modular inverses. The main thing to realize here is that
for two indices where i,j s.t j<i and v[j]<=v[i] the number of such subsequences that include i and j is
2^(i-j-1). So you can coordinate compress the values of the array to use a fenwick tree then update the fenwick tree
with the modular inverse of 2^(j+1) which is 2^(mod-j-2) and multiple a query of the fenwick tree by 2^i getting your result
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
int N;
ll p[(int)3e5+1],v[(int)3e5],ft[(int)3e5+1];
set<int> s;map<int,int> m;
void update(int i, int v){
	v%=mod;
	while (i<=N){
		ft[i]+=v;ft[i]%=mod;i+=(i&(-i));
	}
}
ll query(int i){
	return (i==0?0:(query(i-(i&(-i)))+ft[i])%mod);
}
ll modpower(int n, int p){
	if (p==0) return 1;
	if (p==1) return n;
	if (p%2==0){
		ll res = modpower(n,p/2)%mod;
		return (res*res)%mod;
	}else{
		ll res = modpower(n,p/2)%mod;
		res = (res*res)%mod;
		return (res*n)%mod;
	}
}
int main(){
	setIO();cin >> N;
	for (int i=0;i<N;i++){cin >> v[i];s.insert(v[i]);}
	int c = 1;for (int j:s){m[j]=c++;}
	ll res = 0;
	for (int i=0;i<N;i++){
		res+=(query(m[v[i]])*modpower(2,i))%mod;res%=mod;
		update(m[v[i]],modpower(2,mod-i-2));
	}
	cout << res << "\n";
}
