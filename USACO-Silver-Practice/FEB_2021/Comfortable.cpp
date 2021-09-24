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
int diffx[4] = {-1,1,0,0};
int diffy[4] = {0,0,-1,1};
bool g[2001][2001];
int add = 0;
queue<pair<int,int>> q;
bool checkComfy(int x, int y){
	int count = 0;
	for (int i=0;i<4;i++){
		if (g[x+diffx[i]][y+diffy[i]]) count++;
	}
	return (count==3);
}
void addSquares(int x, int y){
	if (g[x][y]) return;
	int count = 0, p=-1;
	for (int i=0;i<4;i++){
		if (g[x+diffx[i]][y+diffy[i]]) count++;
		else p=i;
	}
	if (count==3){
		q.push({x+diffx[p],y+diffy[p]});
		g[x+diffx[p]][y+diffy[p]]=true;
		add++;
	}
	for (int i=0;i<4;i++){
		if (checkComfy(x+diffx[i],y+diffy[i])) q.push({x+diffx[i],y+diffy[i]});
	}
}
int main(){
	setIO();
	cin >> N;
	vector<pair<int,int>> coord;
	for (int i=0;i<N;i++){
		int x, y; cin >> x >> y;
		coord.pb({x+500,y+500});
	}
	for (int i=0;i<N;i++){
		q.push({coord[i].first,coord[i].second});
		g[coord[i].first][coord[i].second]=true;
		while (!q.empty()){
			addSquares(q.front().first,q.front().second);
			q.pop();
		}
		cout << add << "\n";
	}
}
