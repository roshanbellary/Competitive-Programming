/*
Problem: Hard Calculation
Problem Link: https://atcoder.jp/contests/abc229/tasks/abc229_b
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
string a, b;
int main(){
	setIO();cin >> a >> b;
    reverse(a.begin(),a.end());reverse(b.begin(),b.end());
    for (int i=0;i<min(a.size(),b.size());i++){
        if ((a[i]-'0')+(b[i]-'0')>9){
            cout << "Hard\n"; return 0;
        }
    }
    cout << "Easy\n";
}
