/*
Problem: IOI 2011 Tropical Garden
Problem Link: https://oj.uz/problem/view/IOI11_garden
Notes: I didn't understand how I could account for going back then forwards ie going from 
node 1 to node 0 then node 0 to node 1 then taking a path to node P, so I had to look at 
the editorial to understand the solution.
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include "garden.h"
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
int n, m, s;
vector<int> adj[(int)15e4],adj2[(int)15e4];
bool vis[(int)15e4];
int dist[(int)15e4][2],w[2][2], wh[2],to[(int)15e4];
bool check(int t, int d) {
    if (d < 0) return false;
    if (d == 0) return true;
    if (wh[t] == -1) return false;
    if (wh[t] == t) {
        return d % w[t][t] == 0;
    }
    if (wh[!t] == t) {
        d %= w[t][!t] + w[!t][t];
        return check(!t, d - w[t][!t]);
    }
    return check(!t, d - w[t][!t]);
}
void dfs(int u, int t, int d = 0) {
    memset(vis, 0, sizeof vis);
    queue<int> q;
    dist[u][t] = 0;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto &v : adj2[u]) {
            if (dist[v][t] == -1) {
                dist[v][t] = dist[u][t] + 1;
                q.push(v);
            }
        }
    }
}
void comp(int t) {
    memset(vis, 0, sizeof vis);
    int st = (t == 0 ? s : s + n);
    int u = to[st];
    int d = 1;
    while (!vis[u]) {
        vis[u] = true;
        if (u == s) {
            wh[t] = 0;
            w[t][0] = d;
            break;
        }
        if (u == s + n) {
            wh[t] = 1;
            w[t][1] = d;
            break;
        }
        d++;
        u = to[u];
    }
}
void count_routes(int N, int M, int P, vector<vector<int>> R, int Q, vector<int> G) {
	setIO();
    n=N;m=M;s=P;
    for (int i = 0; i < m; i++) {
        if (adj[R[i][0]].size() < 2) {
            adj[R[i][0]].push_back(R[i][1]);
        }
        if (adj[R[i][1]].size() < 2) {
            adj[R[i][1]].push_back(R[i][0]);
        }
    }
    for (int i = n; i < 2*n; i++) {
        adj[i] = adj[i - n];
        if (adj[i].size() == 2) {
            swap(adj[i][0], adj[i][1]);
        }
    }
    for (int u = 0; u < 2 * n; u++) {
        int v = adj[u][0];
        if (adj[v][0] == u % n) {
            v += n;
        }
        to[u] = v;
        adj2[v].push_back(u);
    }
    memset(w, -1, sizeof w);memset(dist, -1, sizeof dist);
    wh[0] = wh[1] = -1;
    dfs(s, 0);dfs(s + n, 1);
    comp(0);comp(1);
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int ans = 0;
        for (int z = 0; z < n; z++) {
            int cur = 0;
            if (dist[z][0] != -1) {
                int rem = G[i] - dist[z][0];
                cur |= check(0, rem);
            }
            if (dist[z][1] != -1) {
                int rem = G[i] - dist[z][1];
                cur |= check(1, rem);
            }
            ans += cur;
        }
        answer(ans);
    }
}
