/*
Problem: Cheese
Problem Link: https://atcoder.jp/contests/abc229/tasks/abc229_c
Notes: Sort by greatest deliciousness and iterate down to find maximum value
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
struct Cheese{
    int a, b;
};
int N, W;
Cheese r[(int)3e5];
bool sorts(Cheese &a, Cheese &b){
    return (a.a<b.a);
}
int main(){
	setIO();cin >> N >> W;
    for (int i=0;i<N;i++) cin >> r[i].a >> r[i].b;
    sort(r,r+N,sorts);
    ll del = 0;int c = W;
    for (int i=N-1;i>=0;i--){
        int rm = min(c,r[i].b);
        del+=(ll)r[i].a*rm; c-=rm;
    }
    cout << del << "\n";
}
