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
int N, M, S;
pair<ll,ll> V[300000];
int main(){
	setIO();
	cin >> N >> M >> S;
    for(int i=0;i<N;i++) {
        cin >> V[i].first >> V[i].second;
    }
    sort(V,V+N);
    reverse(V,V+N);
	ll dp[N];
	priority_queue<ll> pq;
	ll cost = 0;
    for(int i=0;i<M;i++) {
        pq.push(V[i].second-V[i].first);
        cost+=V[i].first;
    }
    dp[M-1]=cost;
    for(int i = M; i < M + S; i++) {
        pq.push(V[i].second - V[i].first);
        cost += V[i].first;
        cost += pq.top(); pq.pop();
        dp[i] = cost;
    }
    ll ans = dp[M + S - 1];
    while(!pq.empty()) pq.pop();
    for(int i = M + S; i < N; i++) pq.push(V[i].second);
    cost = 0;
    for(int i = M + S - 2; i >= M - 1; i--) {
        pq.push(V[i + 1].second);
        cost += pq.top(); pq.pop();
        ans = max(ans, dp[i] + cost);
    }
    cout << ans << "\n";
}
