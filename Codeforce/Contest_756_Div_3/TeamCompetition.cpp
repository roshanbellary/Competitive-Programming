/*
Problem: 
Problem Link: 
Notes: 
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
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int T;
int main(){
	setIO();cin >> T;
    while (T--){
        int a, b; cin >> a >> b;
        if (b<a) swap(a,b);
        int maxT = 0;
        if ((b-a)/2<=a && 3*(b-a)/2<=b){
            maxT+=(b-a)/2;
            a-=(b-a)/2;
            b-=3*(b-a)/2;
            maxT+=(a/2);
            cout << maxT << "\n";
        }else{
            cout << a << "\n";
        }
    }
}
