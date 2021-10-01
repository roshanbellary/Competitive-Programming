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
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N, M;
int dp[(int)2e5+2];
deque<int> dq;
int lv[(int)2e5+2];
int rv[(int)2e5+2];
signed main() {
	setIO("photo");
    cin >> N >> M;
    fill(rv, rv+N+2, -1);
    for (int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        lv[b+1] = max(lv[b+1], a);
        rv[b] = min(rv[b], a-1);
    }
    for (int i=1;i<=N+1;i++) {
        lv[i] = max(lv[i],lv[i - 1]);
    }
    for (int i=N;i>=1;i--) {
        rv[i]=min(rv[i],rv[i+1]);
    }
    int p1 = 0;
    int p2 = 0;
    dq.push_back(0);
    for (int i=1; i <= N + 1; i++) {
        int l = lv[i], r = rv[i];
        while (p2 <= r) {
            while (!dq.empty() && dp[p2] > dp[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(p2);
            p2++;
        }
        while (! dq.empty() && p1 < l) {
            if (dq.front() == p1) {
                dq.pop_front();
            }
            p1++;
        }
        if (l > r) {
            dp[i] = -1;
            continue;
        }
        else {
            if (dp[dq.front()] == -1) {
                dp[i] = -1;
            }
            else {
                dp[i] = dp[dq.front()] + 1;
            }
        }
    }
    if (dp[N + 1] == -1) {
        cout << -1;
        return 0;
    }
    cout << dp[N + 1] - 1;
}