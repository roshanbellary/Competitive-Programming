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
ll a[1<<20], Q, N=(1<<20);
set<int> s;
int move(int n, int s){
    n+=s;n%=N;n+=N;n%=N;return n;
}
int main(){
	setIO();memset(a,-1,sizeof(a));rn(Q);
    for (int i=0;i<(1<<20);i++)s.insert(i);
    while (Q--){
        int t; ll x, n; rn(t);rn(x);n=(x%N);
        if (t==1){
            auto itr = s.lower_bound(n);
            if (itr==s.end()){
                itr=s.begin();
            }
            a[*itr]=x;
            s.erase(itr);
        }else{
            cout << a[(x%N)] << "\n";
        }
    }
}
