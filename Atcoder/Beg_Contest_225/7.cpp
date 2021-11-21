/*
Problem: 7
Problem Link: https://atcoder.jp/contests/abc225/tasks/abc225_e
Notes: This problem was a big pain since I originally used angles to represent the 7s which proved to be innaccurate due to the doubles.
After converting to fractions, I also ran into errors with my fraction structure.

The premise of this problem is that a 7 takes up a certain angle of the grid. If 2 7's angles intersect then one 7 blocks the other, 
so what you have to do is to find the angle of the bottom half of the 7 and the angle of the top half and get an angle range of the 7.
From there you can use a greedy algorithm to choose the angle ranges that end at the smallest angles(this is optimal as we have more changes
to have another 7 when a range ends sooner than later).
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
struct fract{
    ll n; ll d;
    bool operator<(const fract &a) const{
        return (n*a.d<a.n*d);
    }
    bool operator<=(const fract &a) const{
        return (n*a.d<=a.n*d);
    }
};
int N;
vector<pair<fract,fract>> ang;
int main(){
	setIO();cin >> N;
    for (int i=0;i<N;i++){
        ll x, y;fract x1, x2; cin >> x >> y;
        x1 = {y,x-1}; x2={y-1,x};
        ang.pb({x1,x2});
    }
    sort(ang.begin(),ang.end());
    fract end={0,0}; int res = 0;
    for (int i=0;i<ang.size();i++){
        if (end<=ang[i].s){
            res++;end=ang[i].f;
        }
    }
    cout << res << "\n";
}
