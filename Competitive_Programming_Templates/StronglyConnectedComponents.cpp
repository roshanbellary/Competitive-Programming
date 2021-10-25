//Made by Roshan Bellary
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
const int MAXN=1e5;
vector<int> l[MAXN];//Adjacency List
vector<int> b[MAXN];//Reverse Adjacency List
vector<set<int>> nl;
vector<int> order;
bool v[MAXN],v2[MAXN];
int comp[MAXN];
int col = 0,N;
void reverseDFS(int i){//Topologically sorting vertices
	v[i]=1;
	for (int j:b[i]){
		if (!v[j]) reverseDFS(j);
	}
	order.pb(i);
}
void findComponents(int i, int col){//Finding vertices under SCC
	v2[i]=true;comp[i]=col;
	for (int j:l[i]){
		if (!v2[j]){
			findComponents(j,col);
		}
	}
}
void constructSCC(){//Constructing SCC
	for (int i=0;i<N;i++) if (!v[i]) reverseDFS(i);
	for (int i=order.size()-1;i>=0;i--){
		if (!v2[order[i]]){
			findComponents(order[i],col++);
		}
	}	
}
void decompose(){//Decomposing the components of the SCC to create a DAG
	for (int i=0;i<col;i++) nl.pb(set<int>());
	for (int i=0;i<N;i++){
		for (int j:l[i]){
			if (comp[i]!=comp[j]){
				nl[i].insert(j);
			}
		}
	}
}
int main(){
	setIO(); cin >> N;
	for (int i=0;i<N;i++){
		int s,f; cin >> s >> f;
		l[--s].pb(--f);b[f].pb(s);
	}
	constructSCC();
	decompose();
	cout << col << "\n";//number of strongly connected components
}
