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
int N, M;
bool e[1000][1000],lefts[1000][1000],rights[1000][1000];
int main(){
	setIO(); cin >> N >> M;
	for (int i=0;i<M;i++){
		int u,v; cin >> u >> v;
		e[--u][--v]=e[v][u]=1;
	}
	for (int i=0;i<N;i++) lefts[i][i]=rights[i][i]=1;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (lefts[i][j]&&rights[i][j]) continue;
			if (j) lefts[i][j]=(lefts[i][j-1]&&e[j-1][j])||(rights[j-1][i]&&e[i][j]);
			else if (j<N-1) rights[i][j]=(rights[i][j+1]&&e[j+1][j])||(lefts[j+1][i]&&e[i][j]);
		}
	}
	pair<int,int> pos; bool f = false;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (i<N-1){
				if (rights[i][j]&&lefts[i+1][j]){
					pos={i,j}; f=true;break;
				}
			}
		}
		if (f) break;
	}
	if (!f){cout << "-1\n";return 0;}
	cout << pos.f << " " << pos.s << "\n";
}
