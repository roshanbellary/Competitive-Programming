/*
Problem: Stuck in a Rut
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=1064
Notes: P cool simulation prob
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
const int MN = 1e5;
struct Cow{int x, y,ind;};
struct Event{
	int t,i,j,et,nt;bool y;
	bool operator<(const Event &n) const{
		return n.t<t;
	}
};
bool sortx(Cow &a, Cow &b){return (a.x<b.x);}
bool sorty(Cow &a, Cow &b){return (a.y<b.y);}
int N;
vector<Cow> EA,NO;
bool u[MN];
ll st[MN];
vector<int> l[MN];
priority_queue<Event> col;
bool check(int i, int j){
	return (!(NO[i].y>EA[j].y|| EA[j].x>NO[i].x));
}
int dfs(int ind){
	int n = 1;
	for (int j:l[ind]) n+=dfs(j);
	return n;
}
int main(){
	setIO();rv(N);
	for (int i=0;i<N;i++) st[i]=1e18;
	for (int i=0;i<N;i++){
		Cow n;char c; rv(c);char t; rv(t);rv(n.x,n.y);n.ind=i;
		if (c=='E') EA.pb(n);
		else NO.pb(n);
	}
	for (int i=0;i<NO.size();i++){
		for (int j=0;j<EA.size();j++){
			if (check(i,j)){
				int et = NO[i].x-EA[j].x, nt = EA[j].y-NO[i].y;
				if (et>nt) col.push({et,i,j,et,nt,1});//north beats east
				else if (NO[i].x-EA[j].x<nt) col.push({nt,i,j,et,nt,0});//east beats north
			}
		}
	}
	while (!col.empty()){
		Event e = col.top();col.pop();
		if (!u[EA[e.j].ind] && st[NO[e.i].ind]>e.nt && e.y){u[EA[e.j].ind]=1;l[NO[e.i].ind].pb(EA[e.j].ind);st[EA[e.j].ind]=e.t;}
		else if (!u[NO[e.i].ind] && st[EA[e.j].ind]>e.et){u[NO[e.i].ind]=1;l[EA[e.j].ind].pb(NO[e.i].ind);st[NO[e.i].ind]=e.t;}
	}
	for (int i=0;i<N;i++) cout << dfs(i)-1 << "\n";
}
