/*
USACO 2013 January Contest, Gold Problem 2. Island Travels
http://www.usaco.org/index.php?page=viewproblem2&cpid=230
It took me a while to figure out that the bitmask dp could also have the last island visited 
in order to do the overall dp. After realizing that I was able to solve the problem
*/
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
int R,C;
char g[50][50];bool v[50][50];
int dist[15][15];int n[50][50];
int dx[4]={-1,1,0,0};int dy[4]={0,0,1,-1};
int isles = 0;
void floodfill(int x, int y, int c){
	if (x<0||y<0||x>=R||y>=C) return;
	if (v[x][y]) return;
	v[x][y]=true;
	if (g[x][y]!='X') return;
	n[x][y]=c;
	for (int i=0;i<4;i++){
		floodfill(x+dx[i],y+dy[i],c);
	}
}
int dp[(1<<15)][15];bool done[15];
void setup(){
	for (int i=0;i<50;i++) for (int j=0;j<50;j++) n[i][j]=-1;
	for (int i=0;i<15;i++) for (int j=0;j<15;j++) dist[i][j]=1e9;
}
int main(){
	setIO("island");setup();
	cin >> R >> C;
	memset(dp,-1,sizeof(dp));
	for (int i=0;i<R;i++){
		string s; cin >> s;
		for (int j=0;j<C;j++) g[i][j]=s[j];
	}
	for (int i=0;i<R;i++){
		for (int j=0;j<C;j++){//sets island numbers for squares
			if (!v[i][j] && g[i][j]=='X'){
				floodfill(i,j,isles++);
			}
		}
	}
	int sd[50][50];
	for (int i=0;i<R;i++){
		for (int j=0;j<C;j++){
			if (n[i][j]<0) continue;
			if (!done[n[i][j]]){//finds island that hasn't been done before
				for (int a=0;a<R;a++){
					for (int b=0;b<C;b++){
						sd[a][b]=1e9;
					}
				}
				done[n[i][j]]=true;
				queue<tuple<int,int,int>> q;
				sd[i][j]=0;
				q.push({i,j,0});
				while (!q.empty()){
					int x = get<0>(q.front());
					int y = get<1>(q.front());
					int d = get<2>(q.front());
					q.pop();
					if (d>sd[x][y]) continue;
					if (x){
						if (g[x-1][y]!='.'){
							int nd = d;
							if (n[x-1][y]<0) nd++;
							if (sd[x-1][y]>nd){
								sd[x-1][y]=nd;
								q.push({x-1,y,nd});
							}
						}
					}
					if (y){
						if (g[x][y-1]!='.'){
							int nd=d;
							if (n[x][y-1]<0) nd++;
							if (sd[x][y-1]>nd){
								sd[x][y-1]=nd;
								q.push({x,y-1,nd});
							}
						}
					}
					if (x<R-1){
						if (g[x+1][y]!='.'){
							int nd = d;
							if (n[x+1][y]<0) nd++;
							if (sd[x+1][y]>nd){
								sd[x+1][y]=nd;
								q.push({x+1,y,nd});
							}
						}
					}
					if (y<C-1){
						if (g[x][y+1]!='.'){
							int nd=d;
							if (n[x][y+1]<0) nd++;
							if (sd[x][y+1]>nd){
								sd[x][y+1]=nd;
								q.push({x,y+1,nd});
							}
						}
					}
				}
				for (int a=0;a<R;a++){
					for (int b=0;b<C;b++){
						if (n[a][b]>=0){
							dist[n[i][j]][n[a][b]]=min(dist[n[i][j]][n[a][b]],sd[a][b]);
						}
					}
				}
			}
		}
	}
	for (int i=0;i<(1<<isles);i++){
		for (int j=0;j<isles;j++){
			dp[i][j]=1e9;
		}
	}
	for (int i=0;i<isles;i++){
		dp[(1<<i)][i]=0;
	}
	for (int i=1;i<(1<<isles);i++){
		if (i==(1<<(int)log2(i))) continue;
		for (int j=0;j<isles;j++){
			if (i&(1<<j)){
				int n = (i&(~(1<<j)));
				for (int k=0;k<isles;k++){
					if (n&(1<<k)){
						dp[i][j]=min(dp[i][j],dp[n][k]+dist[k][j]);
					}
				}
			}
		}
	}
	int minV = 1e9;
	for (int i=0;i<isles;i++){
		minV=min(dp[(1<<isles)-1][i],minV);
	}
	cout << minV << "\n";
}
