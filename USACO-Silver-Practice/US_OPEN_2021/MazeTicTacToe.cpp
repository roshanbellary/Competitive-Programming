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
class Square{
	public:
		bool b=false;//blocked space
		bool t=false;//has a character
		char c;//character
		int x,y;//position
};
const int s = 3*3*3*3*3*3*3*3*3;
bool dp[s][25][25];
Square grid[25][25];
int N;
string convert(int n){
	string v = "";
	for (int i=8;i>=0;i--){
		v+=to_string(n/((int)pow(3,i)));
		n%=((int)pow(3,i));
	}
	reverse(v.begin(),v.end());
	return v;
}
bool checkActive(int n, int x, int y){
	int val = 3*x+y;
	string s=convert(n);
	return (s[val]=='0');
}
bool tictac(int n){
	string s = convert(n);
	for (int i=0;i<9;i+=3){
		if (s[i]=='2' && s[i+1]=='1' && s[i+2]=='1'){
			return true;
		}
		if (s[i+2]=='2' && s[i+1]=='1' && s[i]=='1'){
			return true;
		}
	}
	for (int i=0;i<3;i++){
		if (s[i]=='2' && s[i+3]=='1' && s[i+6]=='1'){
			return true;
		}
		if (s[i]=='1' && s[i+3]=='1' && s[i+6]=='2'){
			return true;
		}
	}
	if (s[0]=='2' && s[4]=='1' && s[8]=='1') return true;
	if (s[0]=='1' && s[4]=='1' && s[8]=='2') return true;
	if (s[2]=='2' && s[4]=='1' && s[6]=='1') return true;
	if (s[2]=='1' && s[4]=='1' && s[6]=='2') return true;
	return false;
}
int addVal(int x, int y, int n){
	if (grid[x][y].t){
		if (grid[x][y].c=='O'){
			if (checkActive(n,grid[x][y].x,grid[x][y].y)){
				int pos = 3*(grid[x][y].x)+grid[x][y].y;
				n+=(pow(3,pos));
			}
		}else{
			if (checkActive(n,grid[x][y].x,grid[x][y].y)){
				int pos = 3*(grid[x][y].x)+grid[x][y].y;
				n+=(2*pow(3,pos));
			}
		}
	}
	return n;
}
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void dfs(int x, int y, int n){
	n=addVal(x,y,n);
	if (dp[x][y][n]) return;
	dp[x][y][n]=true;
	if (tictac(n)) return;
	for (int i=0;i<4;i++){
		int nx = x+dx[i],ny=y+dy[i];
		if (nx<0||ny<0||nx>=N||ny>=N) continue;
		if (!grid[nx][ny].b){
			dfs(nx,ny,n);
		}
	}
}
int main(){
	setIO();cin >> N;pair<int,int> pos;
	for (int i=0;i<N;i++){
		string str; cin >> str;
		for (int j=0;j<3*N;j+=3){
			char f,s,t;
			f=str[j];s=str[j+1];t=str[j+2];	
			if (f=='#'){
				grid[i][j/3].b=true;
			}else if (f=='.'){
				grid[i][j/3].b=false;grid[i][j/3].t=false;
			}else if (f!='B'){
				grid[i][j/3].b=false;grid[i][j/3].t=true;
				grid[i][j/3].c=f;grid[i][j/3].x=(s-'0')-1;grid[i][j/3].y=(t-'0')-1;
			}else{
				grid[i][j/3].b=false;grid[i][j/3].t=false;
				pos={i,j/3};
			}
		}
	}
	dfs(pos.first,pos.second,0);
	int posw = 0;
	for (int i=0;i<s;i++){
		if (tictac(i)){
			bool f = false;
			for (int j=0;j<N;j++){
				for (int z=0;z<N;z++){
					if (dp[i][j][z]){posw++;f=true;break;}
				}
				if (f) break;
			}
		}
	}
	cout << posw << "\n";
}
