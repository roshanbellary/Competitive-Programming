/*
IOI 2015 Boxes with souvenirs
https://oj.uz/problem/view/IOI15_boxes
I was unable to think of using a dp on the clockwise and counterclockwise movements since I 
didn't realize how I could consider the full circle movement cases
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
#define mod 1e9+7
ll N, L, K;
vector<int> cw, ccw;
ll memo1[10000010];
ll doCW(int i){
    if (i < 0 || cw.size() == 0)
        return 0;
    if (i >= cw.size())
        return doCW(cw.size() - 1);
    if (memo1[i] != -1)
        return memo1[i];
    return memo1[i] = 1LL * cw[i] * 2 + doCW(i - K);
}
ll memo2[10000010];
ll doCCW(int i){
    if (i < 0 || ccw.size() == 0)
        return 0;
    if (i >= ccw.size())
        return doCCW(ccw.size() - 1);
    if (memo2[i] != -1)
        return memo2[i];
    return memo2[i] = 1LL * ccw[i] * 2 + doCCW(i - K);
}
void delivery(ll n, ll k, ll l, int positions[]){
    memset(memo1, -1, sizeof(memo1));
    memset(memo2, -1, sizeof(memo2));
    N=n;K=k;L=l;
    for (int i=0;i<N;i++){
        if (positions[i]==0||positions[i]==L) continue;
        if (positions[i]>=L/2+(L%2)){
            ccw.pb(L-positions[i]);
        }else{
            cw.pb(positions[i]);
        }
    }
    sort(cw.begin(), cw.end());
    sort(ccw.begin(), ccw.end());
    ll ans = doCW((int)cw.size() - 1) + doCCW((int)ccw.size() - 1);
    for (int i=0;i<=K;i++){
        int d = K-i;
        int a = (int)cw.size()-1-i;
        int b = (int)ccw.size()-1-d;
        ans=min(ans,doCW(a)+doCCW(b)+L);
    }
    cout << ans << "\n";
}
