//Had to use solution and editorial to understand how to solve problem
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
const int MAXN=1e6;
int j = 0;
int n, m, A, B;
int i, l, k;
int tmp1, tmp2;
int scc_size;
vector<int> w, e;
vector<int> edges[MAXN];
vector<int> edges_rev[MAXN];
vector<int> scc[MAXN];
int visited[MAXN];
int order[MAXN];
int scc_inv[MAXN];
int scc_edges[MAXN];
pair<int,int> interval[MAXN];
void reorder(int v) {
  size_t j;
  visited[v] = 1;
  for (j = 0; j < edges[v].size(); ++j)
    if (!visited[edges[v][j]]) reorder(edges[v][j]);
  order[l++] = v;
}
void mark_scc(int v) {
  size_t j;
  visited[v] = 0;
  scc[scc_size].pb(v);
  scc_inv[v] = scc_size;
  for (j = 0; j < edges_rev[v].size(); ++j)
    if (visited[edges_rev[v][j]]) mark_scc(edges_rev[v][j]);
}
void calc_scc() {
  for (i = 0; i < n; ++i) visited[i] = 0;
  l = 0; scc_size = 0;
  for (i = 0; i < n; ++i) if (!visited[i]) reorder(i);
  for (i = n-1; i >= 0; --i) if (visited[order[i]]) {
    mark_scc(order[i]);
    ++scc_size;
  }
  for (i = 0; i < scc_size; ++i) scc_edges[i] = 0;
  for (i = 0; i < n; ++i) for (j = 0; j < edges[i].size(); ++j)
    if (scc_inv[edges[i][j]] != scc_inv[i]) ++scc_edges[scc_inv[i]];
}

void add_interval (pair<int,int> & a, const pair<int,int> & b) {
  if (b.first == -1) return;
  if (a.first == -1) { a = b; return; }
  a.first = min(a.first, b.first);
  a.second = max(a.second, b.second);
}
void calc_reach() {
  queue<int> q;
  for (i = 0; i < n; ++i) visited[i] = 0;
  for (i = 0; i < scc_size; ++i) interval[i] = make_pair(-1, -1);
  for (j = 0; j < e.size(); ++j) {
    l = scc_inv[e[j]];
    add_interval (interval[l], make_pair(j, j));
  }
  for (l = 0; l < scc_size; ++l) if (scc_edges[l] == 0) { visited[l] = 1; q.push(l); }
  while (!q.empty()) {
    k = q.front(); q.pop();
    for (j = 0; j < scc[k].size(); ++j) {
      i = scc[k][j];
      while (!edges_rev[i].empty()) {
        l = scc_inv[edges_rev[i].back()]; edges_rev[i].pop_back();
        add_interval(interval[l], interval[k]);
        if (--scc_edges[l] == 0) {
          visited[l] = 1;
          q.push(l);
        }
      }
    }
  }
}
void mark() {
  for (i = 0; i < n; ++i) visited[i] = 0;
  l = 0;
  for (j = 0; j < w.size(); ++j) if (!visited[w[j]]) reorder(w[j]);
  for (i = 0; i < n; ++i) order[i] = 0;
  order[0] = visited[e[0]];
  for (j = 1; j < e.size(); ++j)
    order[j] = order[j-1] + visited[e[j]];
}
void read_input() {
  vector<pair<int,int>> wt; wt.clear();
  vector<pair<int,int>> et; et.clear();
  cin >> n >> m >> A >> B;
  for (i = 0; i < n; ++i) {
    cin >> tmp1 >> tmp2;
    if (tmp1 == 0) wt.pb(make_pair(tmp2, i));
    else if (tmp1 == A) et.pb(make_pair(tmp2, i));
  }
  sort(wt.begin(), wt.end());
  for (j = 0; j < wt.size(); ++j) w.pb(wt[j].second);
  sort(et.begin(), et.end());
  for (j = 0; j < et.size(); ++j) e.pb(et[j].second);
  while (m-->0) {
    cin >> tmp1 >> tmp2 >> i;
    --tmp1; --tmp2;
    edges[tmp1].pb(tmp2);
    edges_rev[tmp2].pb(tmp1);
    if (i == 2) {
      edges[tmp2].pb(tmp1);
      edges_rev[tmp1].pb(tmp2);
    }
  }
}
void write_output() {
  l = w.size();
  for (--l; l >= 0; --l) {
    tmp1 = interval[scc_inv[w[l]]].first;
    tmp2 = interval[scc_inv[w[l]]].second;
    if (tmp1 == -1) cout << "0\n";
    else if (tmp1 == 0) cout << order[tmp2] << "\n";
    else cout << order[tmp2]-order[tmp1-1] << "\n";
  }
}
int main() {
  read_input();
  calc_scc();
  calc_reach();
  mark();
  write_output();
  return 0;
}
