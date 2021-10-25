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
int N, Q, T;
int v[2003][2000];
void simulate(){
	map<int,int> m;
	for (int i=0;i<N;i++) m[v[0][i]]++;
	for (int i=1;i<=N+2;i++){
		for (int j=0;j<N;j++){
			v[i][j]=m[v[i-1][j]];
		}
		m.clear();
		for (int j=0;j<N;j++){
			m[v[i][j]]++;
		}
	}
}
int main(){
	setIO(); cin >> T;
	for (int l=0;l<T;l++){
		cin >> N;
		for (int i=0;i<N;i++){cin >> v[0][i];}
		simulate();
		cin >> Q;
		for (int i=0;i<Q;i++){
			int x,k; cin >> x >> k;
			if (k<=N+2){
				cout << v[k][x-1] << "\n";
			}else{
				cout << v[N+2][x-1] << "\n";
			}
		}
	}
}
