#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5+5;
int N,M;
vector<int> parent;
vector<vector<int>> l;
queue<int> q; 
void merge(int a, int b) {
	a = parent[a], b = parent[b]; 
	for (int t: rpar[b]) { parent[t] = a; }
	l[a].insert(end(l[a]),begin(l[b]),end(l[b])); 
	l[b].clear();
	if (l[a].size() > 1) q.push(a);
}
int main() { 
	freopen("fcolor.in","r",stdin);
    freopen("fcolor.out","w",stdout);
	cin >> N >> M;
	for (int i=0;i<N;i++) l.push_back(vector<int>()),parent.push_back(0);
	parent.push_back(0);l.push_back(vector<int>());
	for (int i=0;i<M;i++){
		int a,b; cin >> a >> b;
		l[a].push_back(b);
	}
	for (int i=1;i<=N;i++){
		parent[i] = i;
		if (l[i].size() > 1) q.push(i);
	}
	while (q.size()) {
		int x = q.front(); if (l[x].size() <= 1) { q.pop(); continue; }
		int a = l[x].back(); l[x].pop_back();
		if (parent[a] == parent[l[x].back()]) continue;
		merge(a,l[x].back());
	}
	int co = 0;
	for (int i = 1; i <= N; ++i) {
		if (!cnt[par[i]]) cnt[par[i]] = ++co;
		cout << cnt[par[i]] << "\n";
	}
}