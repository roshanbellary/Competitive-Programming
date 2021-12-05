/*
Problem:Comfortable Cows 
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=1110
Notes: 
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
#define f first
#define s second
int mod=1e9+7;
inline void rv(int &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar();
        for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar();
        for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(string &w){
    w="";char c=getchar();
    while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar();}
}
inline void rv(char &c){c=getchar();}
template<typename T, typename ...Types>
void rv(T &n, Types&&... args){rv(n);rv(args...);}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
const int MN = 2001;
int N, g[MN][MN];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int A = 0;
queue<pair<int,int>> q;
bool taken(int x, int y){
	if (x<0||y<0||x>2000||y>2000) return 0;
	return g[x][y];
}
bool comfy(int x, int y){
	if (x<0||y<0||x>2000||y>2000) return false;
	if (!g[x][y]) return false;
	int c = 0;
	int ind = -1;
	for (int i=0;i<4;i++){
		if (taken(x+dx[i],y+dy[i])) c++;
		else{
			ind=i;
		}
	}
	if (c==3) q.push({x+dx[ind],y+dy[ind]});
	return (c==3);
}
void satisfy(int x, int y){
	if (taken(x,y)) return;
	g[x][y]=1;A++;
	comfy(x,y);
	for (int i=0;i<4;i++){
		comfy(x+dx[i],y+dy[i]);
	}
}
int main(){
	setIO();rv(N);
	for (int i=0;i<N;i++){
		int x, y; rv(x, y);A--;
		q.push({x+500,y+500});
		while (!q.empty()){
			auto pt = q.front();q.pop();
			satisfy(pt.f,pt.s);
		}
		cout << A << "\n";
	}
}
