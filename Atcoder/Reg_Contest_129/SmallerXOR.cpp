/*
Problem: Smaller XOR
Problem Link: 
Notes: 
*/
/*
Problem: Range Point Distance
Problem Link: https://atcoder.jp/contests/arc129/tasks/arc129_a
Notes: Check if ranges of [2^i, 2^(i+1)] partially or totally fit into the given range of [L,R] and subtract them
if need be
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
ll N, L, R;
int main(){
	setIO();rn(N);rn(L);rn(R);
    vector<pair<ll,ll>> ranges;
    for (int i=61;i>=0;i--){
        if ((N&(1LL<<i))==0){
            ranges.pb({(1LL<<i),(1LL<<(i+1))-1});
        }
    }
    ll res = R-L+1;
    for (int i=0;i<ranges.size();i++){
        if (ranges[i].s<L||ranges[i].f>R) continue;
        if (ranges[i].f>=L && ranges[i].s<=R) res-=(ranges[i].s-ranges[i].f+1);
        else if (ranges[i].f<L && ranges[i].s>L ) res-=(min(ranges[i].s,R)-L+1);
        else if (ranges[i].f<R && ranges[i].s>R) res-=(R-max(ranges[i].f,L)+1);
    }
    cout << res << "\n";
}
