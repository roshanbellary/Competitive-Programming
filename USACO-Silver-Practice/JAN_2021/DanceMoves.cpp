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
int N, K, p[100000],l[100000], r[100000];
bool v[100000];
pair<int,int> swaps[200000];
set<int> reach[100000];
int main(){
	setIO(); cin >> N >> K;
	for (int i=0;i<N;i++){p[i]=i,reach[i].insert(i);}
	for (int i=0;i<K;i++){cin >> swaps[i].f >> swaps[i].s;swaps[i].f--;swaps[i].s--;}
	for (int i=0;i<K;i++){
		swap(p[swaps[i].f],p[swaps[i].s]);
		reach[p[swaps[i].f]].insert(swaps[i].s);
		reach[p[swaps[i].s]].insert(swaps[i].f);
	}
	for (int i=0;i<N;i++) l[p[i]]=i;
	for (int i=0;i<N;i++){
		if (v[i]) continue;
		vector<int> col;int st = i;
		while (true){
			if (v[st]) break;
			v[st]=true;
			col.pb(st);
			st=l[st];
		}
		for (int v:col){
			if (v==i) continue;
			if (reach[v].size()>reach[i].size()) swap(reach[v],reach[i]);
			for (int j:reach[v]) reach[i].insert(j);
		}
		for (int j:col) r[j]=reach[i].size();
	}
	for (int i=0;i<N;i++){
		cout << r[i] << "\n";
	}
}
