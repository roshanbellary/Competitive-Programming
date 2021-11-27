/*
Problem: Link
Problem Link: https://cses.fi/file/2a3333c827a59499bbbc1c16a74e8c8b29a5d1f3371bb088997da772dd1352d7
Notes: Had to look at solution as I had no idea how to solve the cycle
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
int N, K,nt[500000],ind[500000],p[500000],v[500000],cnt = 0;
queue<int> q;
vector<int> graph[500005];
int dfs(int x){
	int res = 0;
	if(x == 1) res = K;
	for(int i : graph[x]) res = max(res, dfs(i));
	res--;if(res < 0) res = K-1, cnt++; 
	return res;
}
int col[500005], jmp[500005];
void solve_cycle(int x){
	int pl = 0;
	while(!v[x]){
		v[x]=1;col[pl++]=p[x];
		x=nt[x];
	}
	int pcol=col[0];
	for(int i=1; i<2*pl; i++){
		pcol=col[i%pl]=max(pcol-1,col[i%pl]);
	}
	for(int i=pl; i>=0; i--){
		if(!col[i]) jmp[i] = i;
		else jmp[i] = jmp[i+1];
	}
	int tcnt = 0,pos = jmp[0];
	while(pos < pl){
		pos = jmp[min(pos + K, pl)];
		tcnt++;
	}
	for(int i=1; i<min(K,pl); i++){
		int q = pl-K+i;
		int pos = jmp[i];
		int cnt = 0;
		while(pos < q){
			pos = jmp[min(pos + K, pl)];
			cnt++;
		}
		tcnt = min(tcnt, cnt + 1);
	}
	cnt += tcnt;
	memset(col, 0, sizeof(int) * (2*pl+1));
	memset(jmp, 0, sizeof(int) * (pl+1));
}
int main(){
    setIO();
	cin >> N >> K;
	for(int i=1; i<=N; i++){
		int x;cin >> x >> nt[x];
		ind[nt[x]]++;graph[nt[x]].push_back(x);
	}
	for(int i=1; i<=N; i++) if(ind[i] == 0) q.push(i);
	while(!q.empty()){
		int qf = q.front();
		q.pop();v[qf] = 1;ind[nt[qf]]--;
		if(ind[nt[qf]] == 0) q.push(nt[qf]);
	}
	for(int i=1; i<=N; i++){
		if(!v[i]){
			int res = -1;
			for(int j=0; j<graph[i].size(); j++){
				if(!v[graph[i][j]]) continue;
				res = max(res, dfs(graph[i][j]) - 1);
			}
			p[i] = res + 1;
			if(i == 1) p[i] = K + 1;
		}
	}
	for(int i=1; i<=N; i++) if(!v[i]) solve_cycle(i);
	cout << cnt << "\n";
}
