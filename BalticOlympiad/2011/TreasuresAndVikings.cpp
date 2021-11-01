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
struct Dist{int x, y, d;};
int N, M,reach[700][700], dist[700][700],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
char g[700][700];
bool r[700][700];
void clearReach(){for (int i=0;i<N;i++) for (int j=0;j<M;j++) reach[i][j]=1e9;}
void clearDist(){for (int i=0;i<N;i++) for (int j=0;j<M;j++) dist[i][j]=1e9;}
void setReach(){
	clearReach();
	for (int i=0;i<N;i++){
		int minV = 1e9;
		for (int j=0;j<M;j++){
			if (g[i][j]=='I'){minV=1e9;reach[i][j]=1e9;}
			else{minV=min(minV,dist[i][j]);reach[i][j]=min(minV,reach[i][j]);}
		}
		minV=1e9;
		for (int j=M-1;j>=0;j--){
			if (g[i][j]=='I'){minV=1e9;reach[i][j]=1e9;}
			else{minV=min(minV,dist[i][j]);reach[i][j]=min(minV,reach[i][j]);}
		}
	}
	for (int i=0;i<M;i++){
		int minV = 1e9;
		for (int j=0;j<N;j++){
			if (g[j][i]=='I'){minV=1e9;reach[j][i]=1e9;}
			else{minV=min(minV,dist[j][i]);reach[j][i]=min(minV,reach[j][i]);}
		}
		minV=1e9;
		for (int j=N-1;j>=0;j--){
			if (g[j][i]=='I'){minV=1e9;reach[j][i]=1e9;}
			else{minV=min(minV,dist[j][i]);reach[j][i]=min(minV,reach[j][i]);}
		}
	}
}
int main(){
	setIO();cin >> N >> M;
	pair<int,int> pos,v,t; clearDist();
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			cin >> g[i][j];
			if (g[i][j]=='Y') pos={i,j};
			else if (g[i][j]=='V') v={i,j};
			else if (g[i][j]=='T') t={i,j};
		}
	}
	queue<Dist> q;q.push({v.f,v.s,0}); dist[v.f][v.s]=0;
	while (!q.empty()){
		Dist p = q.front(); q.pop();
		if (dist[p.x][p.y]<p.d) continue;p.d++;
		for (int i=0;i<4;i++){
			int nx = p.x+dx[i], ny = p.y+dy[i];
			if (nx<0||nx>=N||ny<0||ny>=M) continue;
			if (dist[nx][ny]>p.d && g[nx][ny]!='I'){
				dist[nx][ny]=p.d;q.push({nx,ny,p.d});
			}
		}
	}
	setReach();clearDist();q.push({pos.f,pos.s,0}); dist[pos.s][pos.f]=0;
	while (!q.empty()){
		Dist p = q.front();q.pop();
		if (dist[p.x][p.y]<p.d) continue;
		r[p.x][p.y]=true;p.d++;
		for (int i=0;i<4;i++){
			int nx = p.x+dx[i], ny = p.y+dy[i];
			if (nx<0||nx>=N||ny<0||ny>=M) continue;
			if (g[nx][ny]=='I' || dist[nx][ny]<=p.d || p.d>=reach[nx][ny]) continue;
			dist[nx][ny]=p.d;q.push({nx,ny,p.d});
		}
	}
	cout << (r[t.f][t.s]?"YES\n":"NO\n");
}
