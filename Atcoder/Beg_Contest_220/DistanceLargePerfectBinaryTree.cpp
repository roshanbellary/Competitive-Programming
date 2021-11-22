/*
Problem: Distance on Large Perfect Binary Tree
Problem Link: https://atcoder.jp/contests/abc220/tasks/abc220_e
Notes: The motherload of annoying problems. Took me way too long to do due to stupid mistakes with overflow.
Basic premise is that for any node at depth i all paths made up of a and b lengths such that a+b=D have a total count of 2^(D-2)
while a path of length D that originates directly from a node has a total count of 2^D. after summing it up for all N layers we get our
answer divided by 2 as we can also swap vertices so you multiply by 2 at the end.
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
int mod=998244353;
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
ll N, D,res=0;
ll modpower(int p){
    if (p==0) return 1;
    if (p%2==0){
        ll r = modpower(p/2);
        return (r*r)%mod;
    }else{
        ll r = modpower(p/2);
        return (((r*r)%mod)*2)%mod;
    }
}
int main(){
	setIO();cin >> N >> D;
    for (int i=0;i<N;i++){
        if (i+D<N){
            res+=(modpower(i)*modpower(D))%mod;res%=mod;
            ll add = (modpower(i)*modpower(D-2));add%=mod;
            add*=(D-1);add%=mod;res+=add;res%=mod;
        }else if (2*(N-i-1)>=D){
            ll add = (modpower(i)*modpower(D-2));add%=mod;
            add*=(min(2*(N-1-i)-D+1,D-1));add%=mod;
            res+=add;res%=mod;
        }
    }
    cout << (2*res)%mod << "\n";
}
