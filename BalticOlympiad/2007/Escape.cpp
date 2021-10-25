/*
BOI 2007 Escape P1
https://cses.fi/file/e94ce10cb0896bc8ea40b85d6092e6e6a5cb763a81ce13f9e8cf7bafd6aeb690
Had to look at editorial to solve this problem with maximum flows
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
int L, W, N;
pair<int,int> arr[255];
pair<pair<int,int>,int> edges[2 * (2 * (250 * 251 / 2 + 250 * 3) + 5)];
int last[1010], dist[1010];
int S, T;
int cnt = 0;

bool bfs() {
    memset(dist,1e9,sizeof(dist));
    queue<int> q;
    dist[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = last[u]; i != -1; i = edges[i].second) {
            int v = edges[i].first.first;
            int w = edges[i].first.second;
            if (dist[v] == 1e9 && w) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[T] != 1e9;
}

int dfs(int u, int flow) {
    if (u == T) {
        return flow;
    }
    int ans = 0;
    for (int i = last[u]; i != -1; i = edges[i].second) {
        int v = edges[i].first.first;
        int w = edges[i].first.second;
        if (dist[v] == dist[u] + 1 && w) {
            int res = dfs(v, min(flow, w));
            ans += res;
            edges[i].first.second -= res;
            edges[i ^ 1].first.second += res;
            flow -= res;
            if (!flow) {
                break;
            }
        }
    }
    return ans;
}

void addEdge(int a, int b, int d) {
    edges[cnt] = {{b, d}, last[a]};
    last[a] = cnt++;
    edges[cnt] = {{a, 0}, last[b]};
    last[b] = cnt++;
}

ll distSq(pair<int,int> a, pair<int,int> b) {
    return pow(b.first - a.first, 2) + pow(b.second - a.second, 2);
}

int main() {
    setIO();
    cin >> L >> W >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    memset(last,-1,sizeof(last));
    S = 2 * N + 1, T = 2 * N + 2;
    for (int i = 1; i <= N; i++) {
        addEdge(i, i + N, 1);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (distSq(arr[i], arr[j]) <= pow(200, 2)) {
                addEdge(i + N, j, 1e9);
                addEdge(j + N, i, 1e9);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (arr[i].second <= 100) {
            addEdge(S, i, 1e9);
        }
        if (W - arr[i].second <= 100) {
            addEdge(i + N, T, 1e9);
        }
    }
    int ans = 0;
    while (bfs()) {
        ans += dfs(S, 1e9);
    }
    cout << ans << "\n";
}
