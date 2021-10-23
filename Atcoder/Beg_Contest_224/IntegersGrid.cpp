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
struct Square{
	int r,c,a,i,ai;
};
bool cmp(Square &a, Square &b){
	return (a.a>b.a);
}
int H, W, N;
vector<Square> grid;
int dp[(int)2e5];
map<int,int> rows;
map<int,int> cols;
set<int> fr;
set<int> fc;
int main(){
	setIO();cin >> H >> W >> N;
	for (int i=0;i<N;i++){
		int r,c,a;cin >> r >> c >> a;
		grid.pb({r,c,a,0,i});
	}
	sort(grid.begin(),grid.end(),cmp);
	for (int i=0;i<N;i++){grid[i].i=i;}
	for (int i=0;i<N;i++){
		int j=i+1;
		while (j<N){
			if (grid[j].a==grid[i].a){
				j++;
			}else{
				break;
			}
		}
		for (int z=i;z<j;z++){
			dp[grid[z].ai]=0;
			int mv = 0;
			if (fr.find(grid[z].r)!=fr.end()){
				mv = rows[grid[z].r]+1;
			}
			if (fc.find(grid[z].c)!=fc.end()){
				mv = max(mv,cols[grid[z].c]+1);
			}
			dp[grid[z].ai]=mv;
		}
		for (int z=i;z<j;z++){
			rows[grid[z].r]=max(dp[grid[z].ai],rows[grid[z].r]);
			cols[grid[z].c]=max(dp[grid[z].ai],cols[grid[z].c]);
			fr.insert(grid[z].r);fc.insert(grid[z].c);
		}
		i=j-1;
	}
	for (int i=0;i<N;i++){
		cout << dp[i] << "\n";
	}
}
