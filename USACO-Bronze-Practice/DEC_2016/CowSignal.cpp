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
int M, N, K;
char g[10][10];
char ng[100][100];
int main(){
	setIO("cowsignal"); cin >> M >> N >> K;
	for (int i=0;i<M;i++){
		string s; cin >> s;
		for (int j=0;j<N;j++){
			g[i][j]=s[j];
		}
	}
	for (int i=0;i<M;i++){
		for (int j=0;j<N;j++){
			for (int z=K*i;z<K*i+K;z++){
				for (int a=K*j;a<K*j+K;a++){
					ng[z][a]=g[i][j];
				}
			}
		}
	}
	for (int i=0;i<M*K;i++){
		for (int j=0;j<N*K;j++){
			cout << ng[i][j];
		}
		cout << "\n";
	}
}
