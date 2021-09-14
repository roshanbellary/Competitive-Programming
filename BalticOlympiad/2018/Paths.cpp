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
#define mod 1e9+7
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N, M, K;
int c[100000];
vector<vector<int>> l;
int main(){
	setIO();
	cin >> N >> M >> K;
	for (int i=0;i<N;i++){cin >> c[i];c[i]--;}
	for (int i=0;i<N;i++){
		l.pb(vector<int>());
	}
	for (int i=0;i<M;i++){
		int a,b; cin >> a >> b;a--;b--;
		if (c[a]!=c[b]){
			l[a].pb(b);
			l[b].pb(a);
		}
	}
	ll dp[N][K][(1<<K)];
	for (int i=0;i<N;i++){
		for (int a=0;a<K;a++){
			for (int j=0;j<(1<<K);j++){
				dp[i][a][j]=0;
			}
		}
	}
	for (int i=0;i<N;i++){
		dp[i][0][(1<<c[i])]=1;
	}
	for (int a=1;a<K;a++){
		for (int i=0;i<N;i++){
			for (int j:l[i]){
				for (int k=0;k<(1<<K);k++){
					if ((k&(1<<c[i]))!=0) continue;
					dp[i][a][(k|(1<<c[i]))]+=dp[j][a-1][k];
				}
			}
		}
	}
	ll sum = 0;
	for (int i=0;i<N;i++){
		for (int a=0;a<K;a++){
			for (int j=0;j<(1<<K);j++){
				sum+=dp[i][a][j];
			}
		}
	}

	cout << sum-N << "\n";
}
