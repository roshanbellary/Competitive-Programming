/*
Problem: Placing Rectangles
Problem Link: https://atcoder.jp/contests/abc223/tasks/abc223_e
Notes: Casework problem in regards to placing rectangles. One stupid typo made me spend way too long
debugging for it.
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

ll X, Y; ll A[3];
bool check2(ll A1, ll A2, ll H, ll W){
    if ((A1+H-1)/H<W){
        if (A2<=H*(W-(A1+H-1)/H)) return true;
    }
    if ((A1+W-1)/W<H){
        if (A2<=W*((H-(A1+W-1)/W))) return true;
    }
    return false;
}
int main(){
	setIO();cin >> X >> Y;for (int i=0;i<3;i++) cin >> A[i];
    //Case YxX:
    for (int i=0;i<3;i++){
        if ((A[i]+Y-1)/Y>=X) continue;
        if (check2(A[(i+1)%3],A[(i+2)%3],X-(A[i]+Y-1)/Y,Y)){cout << "Yes\n"; return 0;} 
    }
    //Case XxY
    for (int i=0;i<3;i++){
        if ((A[i]+X-1)/X >= Y) continue;
        if (check2(A[(i+1)%3],A[(i+2)%3],Y-(A[i]+X-1)/X,X)){cout << "Yes\n"; return 0;} 
    }
    cout << "No\n";
}
