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
struct Pos{
	int x, y, d;
};
int N, M,dm[1000][1000],r[1000][1000];
char g[1000][1000];
pair<int,int> pos,part;
queue<Pos> q;
int dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
char dir[4] = {'D','U','L','R'};
string d = "";
void dfs(int x, int y){
	for (int i=0;i<4;i++){
		int nx = x+dx[i]; int ny = y+dy[i];
		if (nx<0||ny<0||nx>=N||ny>=M) continue;
		if (r[nx][ny]==r[x][y]-1){
			d+=dir[i];
			if (r[nx][ny]) dfs(nx,ny);
			break;
		}
	}
}
int main(){
	setIO();cin >> N >> M;
	for (int i=0;i<N;i++) for (int j=0;j<M;j++){dm[i][j]=1e9;r[i][j]=1e9;}
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			cin >> g[i][j];
			if (g[i][j]=='M'){q.push({i,j,0});dm[i][j]=0;}
			if (g[i][j]=='A') pos={i,j};
		}
	}
	while (!q.empty()){
		Pos n = q.front();q.pop();
		if (n.d>dm[n.x][n.y]) continue;
		int d = n.d+1;
		for (int i=0;i<4;i++){
			int nx=n.x+dx[i], ny=n.y+dy[i];
			if (nx<0||ny<0||nx>=N||ny>=M) continue;
			if (g[nx][ny]=='#'|| dm[nx][ny]<=d) continue;
			dm[nx][ny]=d;q.push({nx,ny,d});
		}
	}
	q.push({pos.f,pos.s,0});r[pos.f][pos.s]=0;
	while (!q.empty()){
		Pos n = q.front();q.pop();int d = n.d+1;
		for (int i=0;i<4;i++){
			int nx = n.x+dx[i],ny=n.y+dy[i];
			if (nx<0||ny<0||nx>=N||ny>=M) continue;
			if (g[nx][ny]=='#'||dm[nx][ny]<=d||r[nx][ny]<=d) continue;
			q.push({nx,ny,d});
			r[nx][ny]=d;
		}
	}
	bool f = 0;
	for (int i=0;i<N;i++){
		if (r[i][0]<1e9){
			f=1;part={i,0};
			break;
		}
		if (r[i][M-1]<1e9){
			f=1;part={i,M-1};
			break;
		}
	}
	if (!f){
		for (int i=0;i<M;i++){
			if (r[0][i]<1e9){
				f=1;part={0,i};
				break;
			}
			if (r[N-1][i]<1e9){
				f=1;part={N-1,i};
				break;
			}
		}
	}
	if (!f){cout << "NO\n";return 0;}
	cout << "YES\n";
	dfs(part.f,part.s);
	cout << d.size() << "\n";
	reverse(d.begin(),d.end());
	cout << d << "\n";

}
