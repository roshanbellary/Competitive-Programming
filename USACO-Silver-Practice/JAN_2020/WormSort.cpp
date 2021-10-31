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
int N, M,p[100000],c[100000], w[100000];
vector<pair<int,int>> l[100000];
void dfs(int ind, int comp, int w){
	c[ind]=comp;
	if (l[ind].size()==0) return;
	for (pair<int,int> j:l[ind]){
		if (c[j.first]==-1 && j.second>=w) dfs(j.first,comp,w);
	}
}
bool check(int w){
	memset(c,-1,sizeof(c));
	int comp = 0;
	for (int i=0;i<N;i++){
		if (c[i]==-1) dfs(i,comp++,w);
	}
	for (int i=0;i<N;i++){
		if (c[p[i]]!=c[i]) return false;
	}
	return true;
}
int main(){
	setIO("wormsort"); cin >> N >> M;
	for (int i=0;i<N;i++){cin >> p[i];p[i]--;}
	for (int i=0;i<M;i++){
		int we, u, v; cin >> u >> v >> we;
		l[--u].pb({--v,we});
		l[v].pb({u,we});
		w[i]=we;
	}
	if (check(1e9+1)){
		cout << "-1\n";return 0;
	}
	sort(w,w+M);
	int s = 0,f=M-1;
	while (s!=f){
		int mid = (s+f+1)/2;
		if (check(w[mid])) s=mid;
		else f=mid-1;
	}
	cout << w[s] << "\n";
}
