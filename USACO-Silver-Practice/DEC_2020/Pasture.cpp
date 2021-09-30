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
int N;
class Cow{
	public:
		int x,y;
};
bool sortx(Cow &a, Cow &b){return (a.x<b.x);}
bool sorty(Cow &a, Cow &b){return (a.y<b.y);}
vector<Cow> f;
bool g[2501][2501];
ll dp[2501][2501];
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++){
		Cow n; cin >> n.x >> n.y;
		f.pb(n);
	}
	for (int i=0;i<N;i++) for (int j=0;j<N;j++) dp[i][j]=0;
	sort(f.begin(),f.end(),sortx);
	map<int,int> x; map<int,int> y; int count = 1;
	for (int i=0;i<N;i++){ 
		f[i].x=count;count++;
	}
	sort(f.begin(),f.end(),sorty); count = 1;
	for (int i=0;i<N;i++){
		f[i].y=count;count++;
	}
	for (int i=0;i<N;i++){
		g[f[i].x][f[i].y]=true;
	}
	for (int i=0;i<=N;i++){
		for (int j=0;j<=N;j++){
			if (g[i][j]) dp[i][j]++;
			if (i) dp[i][j]+=dp[i-1][j];
			if (j) dp[i][j]+=dp[i][j-1];
			if (i&&j) dp[i][j]-=dp[i-1][j-1];
		}
	}
	ll sets = 0;
	for (int i=0;i<N;i++){
		for (int j=i;j<N;j++){
			int sx = min(f[i].x,f[j].x);
			int sy = f[i].y;
			int fx = max(f[i].x,f[j].x);
			int fy = f[j].y;
			ll right = dp[N][fy]-dp[fx-1][fy]-dp[N][sy-1]+dp[fx-1][sy-1];
			ll left = dp[sx][fy]-dp[sx][sy-1];
			sets+=(right*left);
		}
	}
	cout << sets+1 << "\n";
}
