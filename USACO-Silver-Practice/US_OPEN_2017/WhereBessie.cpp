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
int mod = 1e9+7;
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
char c[21][21];
vector<int> n(26,0);
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void floodfill(int x, int y, int bx, int by, int ux, int uy, vector<vector<bool>> &v, char t){
	if ((x<bx)||(x>ux)||(y<by)||(y>uy))return;
	if (c[x][y]!=t) return;
	if (v[x][y]) return;
	v[x][y]=true; 
	for (int i=0;i<4;i++){
		floodfill(x+dx[i],y+dy[i],bx,by,ux,uy,v,t);
	}
}
bool checkRegion(int bx, int by, int ux, int uy){
	vector<vector<bool>> g(21,vector<bool>(21,false));
	for (int i=bx;i<=ux;i++){
		for (int j=by;j<=uy;j++){
			if (!g[i][j]){
				n[c[i][j]-'A']++;
				floodfill(i,j,bx,by,ux,uy,g,c[i][j]);
			}
		}
	}
	int count = 0;
	int count2 = 0;
	int count1 = 0;
	for (int i=0;i<26;i++){
		if (n[i]>0) count++;
		if (n[i]==2) count2++;
		if (n[i]==1) count1++;
	}
	return ((count==2)&&(count2==1)&&(count1==1));
}
int main(){
	setIO("where");
	cin >> N;
	for (int i=0;i<N;i++){
		string s; cin >> s;
		for (int j=0;j<N;j++){
			c[i][j]=s[j];
		}
	}
	vector<pair<pair<int,int>,pair<int,int>>> grids;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			for (int a=i;a<N;a++){
				for (int b=j;b<N;b++){
					fill(n.begin(),n.end(),0);
					if (checkRegion(i,j,a,b)){
						grids.pb({{i,j},{a,b}});
					}
				}
			}
		}
	}
	int res = grids.size();
	vector<bool> contain(grids.size(),false);
	for (int i=0;i<grids.size();i++){
		for (int j=0;j<grids.size();j++){
			if (i==j) continue;
			if ((grids[j].first.first>=grids[i].first.first)&&(grids[j].first.second>=grids[i].first.second)){
				if ((grids[j].second.first<=grids[i].second.first)&&(grids[j].second.second<=grids[i].second.second)){
					contain[j]=true;
				}
			}
		}
	}
	int counts = 0;
	for (int i=0;i<grids.size();i++){
		if (!contain[i]) counts++;
	}
	cout << counts << "\n";
}
