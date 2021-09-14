#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
const int s = 500;
int H, W;
bool g[s][s];
ll dp[s][s];
bool checkIn(int x, int y){
	return ((x>=0)&&(x<H)&&(y>=0)&&(y<W));
}
int main(){
	setIO();
	cin >> H >> W;
	for (int i=0;i<H;i++){
		string s; cin >> s;
		for (int j=0;j<W;j++){
			dp[i][j]=1e18;
			if (s[j]=='.') g[i][j]=true;
			else g[i][j]=false;
		}
	}
	priority_queue<pair<int,pair<int,int>>> q;
	q.push(make_pair(0,make_pair(0,0)));
	dp[0][0]=0;
	int dx[4]={-1,0,1,0};
	int dy[4]={0,-1,0,1};
	while (!q.empty()){
		int i = q.top().second.first;
		int j = q.top().second.second;
		int d = -q.top().first;
		q.pop();
		if (d>dp[i][j]) continue;
		for (int z=0;z<4;z++){
			if (checkIn(i+dx[z],j+dy[z])){
				if ((g[i+dx[z]][j+dy[z]])&&(dp[i+dx[z]][j+dy[z]]>d)){
					dp[i+dx[z]][j+dy[z]]=d;
					q.push(make_pair(-d,make_pair(i+dx[z],j+dy[z])));
				}
			}
		}
		d++;
		for (int a=-2;a<=2;a++){
			for (int b=-2;b<=2;b++){
				if ((abs(a)==2)&&(abs(b)==2)) continue;
				if (checkIn(i+a,j+b)){
					if (dp[i+a][j+b]>d){
						dp[i+a][j+b]=d;
						q.push(make_pair(-(d),make_pair(i+a,j+b)));
					}
				}
			}
		}
	}
	cout << dp[H-1][W-1] << "\n";
}
