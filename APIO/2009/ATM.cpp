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
int N, M, S, P;
vector<int> l[(int)5e5],b[(int)5e5];
vector<int> order;
vector<set<int>> nl;
vector<vector<int>> bl;
vector<int> nv;vector<bool> nb;
vector<int> mv;
int comp[(int)5e5],p[(int)5e5];
bool v[(int)5e5],v2[(int)5e5],r[(int)5e5];
int col = 0;
void reverseDFS(int i){
	v[i]=true;
	for (int j:b[i]){
		if (!v[j]){
			reverseDFS(j);
		}
	}
	order.pb(i);
}
void dfs(int i, int col){
	v2[i]=true;comp[i]=col;
	for (int j:l[i]){
		if (!v2[j]){
			dfs(j,col);
		}
	}
}
void decompose(){
	for (int i=0;i<col;i++) nl.pb(set<int>()),nv.pb(0),nb.pb(0),mv.pb(0),bl.pb(vector<int>());
	for (int i=0;i<N;i++){
		nv[comp[i]]+=p[i];
		if (r[i]) nb[comp[i]]=true;
		for (int j:l[i]){
			if (comp[i]!=comp[j]) nl[comp[i]].insert(comp[j]);
		}
	}
}
void constructSCC(){
	for (int i=0;i<N;i++){
		if (!v[i]) reverseDFS(i);
	}
	for (int i=order.size()-1;i>=0;i--){
		if (!v2[order[i]]){
			dfs(order[i],col++);
		}
	}
	decompose();
	for (int i=0;i<col;i++){
		for (int j:nl[i]){
			bl[j].pb(i);
		}
	}
}
vector<int> norder;
vector<bool> vorder;
void nordering(int i){
	for (int j:nl[i]){
		if (!vorder[j]){
			vorder[j]=true;
			nordering(j);
		}
	}
	norder.pb(i);
}
int main(){
	setIO();cin >> N >> M;
	for (int i=0;i<M;i++){
		int s,f; cin >> s >> f;
		l[--s].pb(--f);
		b[f].pb(s);
	}
	for (int i=0;i<N;i++) cin >> p[i];
	cin >> S >> P;--S;
	for (int i=0;i<P;i++){
		int v; cin >> v;r[--v]=true;
	}
	constructSCC();
	for (int i=0;i<col;i++) vorder.pb(false);
	vorder[comp[S]]=true;
	nordering(comp[S]);
	reverse(norder.begin(),norder.end());
	for (int i=0;i<norder.size();i++){
		mv[norder[i]]=nv[norder[i]];
		int maxv = 0;
		for (int j:bl[norder[i]]){
			maxv = max(maxv,mv[j]);
		}
		mv[norder[i]]+=maxv;
	}
	int maxv=0;
	for (int i=0;i<col;i++){
		if (nb[i]) maxv=max(maxv,mv[i]);
	}
	cout << maxv << "\n";
}
