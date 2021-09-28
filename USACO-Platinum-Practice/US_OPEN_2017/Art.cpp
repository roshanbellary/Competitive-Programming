/*
USACO 2017 US Open Contest, Platinum Problem 1. Modern Art
http://www.usaco.org/index.php?page=viewproblem2&cpid=744
Cool problem, the hard part was figuring out how to find the rectangles intersecting which I had to 
use the editorial for.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
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
int g[1001][1001];
class Rectangle{
	public:
		int sx,sy,fx,fy;
		int c;
		const bool operator<(const Rectangle &a) const {
			return (c<a.c);
		}
};
set<Rectangle> col;
int main(){
	setIO("art");
	cin >> N;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			cin >> g[i][j];
		}
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (g[i][j]==0) continue;
			if (col.size()==0){
				Rectangle n;
				n.c=g[i][j];n.sx=i;n.sy=j;n.fx=i;n.fy=j;
				col.insert(n);
			}else{
				Rectangle comp;
				comp.c=g[i][j];
				auto itr = col.lower_bound(comp);
				if (itr==col.end()){
					Rectangle n; n.c=g[i][j];
					n.sx=i;n.sy=j;n.fx=i;n.fy=j;
					col.insert(n);
				}else if (itr->c==g[i][j]){
					Rectangle n;
					n.c=g[i][j];
					n.sx=min(itr->sx,i);
					n.fx=max(itr->fx,i);
					n.sy=min(itr->sy,j);
					n.fy=max(itr->fy,j);
					col.erase(itr);
					col.insert(n);
				}else{
					Rectangle n;
					n.c=g[i][j];
					n.sx=i;n.sy=j;n.fx=i;n.fy=j;
					col.insert(n);
				}
			}
		}
	}
	int grid[N][N];
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			grid[i][j]=0;
		}
	}
	vector<bool> c(N*N+1,false);
	for (Rectangle s:col){
		grid[s.sx][s.sy]++;
		if (s.fy<N-1) grid[s.sx][s.fy+1]--;
		if (s.fx<N-1) grid[s.fx+1][s.sy]--;
		if ((s.fx<N-1)&&(s.fy<N-1)) grid[s.fx+1][s.fy+1]++;
	}
	int pres = 0;
	int count = N*N;
	for (int i=1;i<N;i++){
		grid[i][0]+=grid[i-1][0];
		grid[0][i]+=grid[0][i-1];
	}
	for (int i=1;i<N;i++){
		for (int j=1;j<N;j++){
			grid[i][j]+=(grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1]);
		}
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if ((grid[i][j]!=0)&&(!c[g[i][j]])&&(grid[i][j]>1)){
				count--;
				c[g[i][j]]=true;
			}
		}
	}
	if (log2(count)!=(int)(log2(count))) cout << count << "\n";
	else cout << count-1 << "\n";
}
