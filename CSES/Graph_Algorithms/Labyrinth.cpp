//CSES Labyrinth Graph Algorithms Problem
//https://cses.fi/problemset/task/1193
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
int N, M;
pair<bool,bool> grid[1000][1000];
int dist[1000][1000];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
string dir[4]={"D","U","L","R"};
string path = "";
void dfs(int x, int y){
	for (int i=0;i<4;i++){
		int nx = x+dx[i];int ny=y+dy[i];
		if (nx<0||nx>=N||ny<0||ny>=M) continue;
		if (dist[nx][ny]==dist[x][y]-1){
			path+=dir[i];
			dfs(nx,ny);
			return;
		}
	}
}
int main(){
	setIO();
	cin >> N >> M;
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			dist[i][j]=1e9;
		}
	}
	pair<int,int> st;
	pair<int,int> fi;
	for (int i=0;i<N;i++){
		string s; cin >> s;
		for (int j=0;j<M;j++){
			if (s[j]=='#') grid[i][j].first=false;
			else{
				grid[i][j].first=true;
				if (s[j]=='A') st={i,j};
				else if (s[j]=='B') fi={i,j};
			}
		}
	}
	queue<pair<int,int>> q;
	q.push({st.first,st.second});
	dist[st.first][st.second]=0;
	while (!q.empty()){
		int xc = q.front().first;
		int yc = q.front().second;
		int d = dist[xc][yc]+1;
		q.pop();
		for (int i=0;i<4;i++){
			int nx = xc+dx[i];
			int ny = yc+dy[i];
			if (nx<0||ny<0||nx>=N||ny>=M) continue;
			if (!grid[nx][ny].first) continue;
			if (dist[nx][ny]>d){
				dist[nx][ny]=d;
				q.push({nx,ny});
			}
		}
	}
	if (dist[fi.first][fi.second]!=1e9){
		cout << "YES\n";
		dfs(fi.first,fi.second);
		cout << path.size() << "\n";
		reverse(path.begin(),path.end());
		cout << path << "\n";
	}else cout << "NO\n";
}
