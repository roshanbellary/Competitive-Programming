/*
Problem: BITWISE EXPRESSIONS
Problem Link: https://cses.fi/file/981b6e446ea12a87e2042caa35339a542f2d91efb8e7929db5c9d7fa762314ee
Notes: Had to look at solution
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
    n=0;int m=1;char c=getchar();if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar();if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){double p = 0.1;c=getchar();for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}}
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){double p = 0.1;c=getchar();for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}}
    n*=m;
}
inline void rv(string &w){w="";char c=getchar();while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar();}}
inline void rv(char &c){c=getchar();}
template<typename T, typename ...Types>
inline void rv(T &n, Types&&... args){rv(n);rv(args...);}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
const int MAXN = 301;
int N, M;
int l[MAXN], r[MAXN];
vector<int> pos[MAXN];
bool good(vector<int> &pos, int msk){
	vector<int> choice[32];
	for(auto &i : pos){
		if(l[i] == r[i]){
			msk &= ~l[i];
			continue;
		}
		int j = 30;
		while((l[i] >> j) == (r[i] >> j)) j--;
		int val = (l[i] >> (j + 1)) << (j + 1);
		msk &= ~val;
		choice[j].push_back(r[i] - val);
	}
	priority_queue<pair<int,int>> pq;
	for(int i = 30; i >= 0; i--){
		for(auto &j : choice[i]) pq.emplace(i, j);
		if((msk >> i) & 1){
			if(pq.empty()) return 0;
			auto x = pq.top(); pq.pop();
			if(x.f > i) return 1;
			msk^=(1<<i);x.s^=(1<<i);
			int pos = i;
			if(x.s > 0){
				while((x.s >> pos) == 0) pos--;
				choice[pos].push_back(x.s);
			}
		}
	}
	return 1;
}
bool good(int msk){
	for(int i=0; i<M; i++) if(!good(pos[i], msk)) return 0;
	return 1;
}
int main(){
	rv(N,M);
	int cur = 0;
	for(int i=0; i<M; i++){
		int x; rv(x);
		pos[i].resize(x);fill(pos[i].begin(),pos[i].end(),cur);
		cur+=x;
	}
	for(int i=0; i<N; i++) rv(l[i],r[i]);
	int res = 0;
	for(int i=30; i>=0; i--) if(good(res | (1 << i))) res |= (1 << i);
	cout << res << "\n";
}
