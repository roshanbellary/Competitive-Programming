/*
Problem: 
Problem Link: 
Notes: 
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef pair<int,int> pi;
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
int N,ans,eq;
vector<pi> cows;
void solve() {
	sort(begin(cows),end(cows));
	for (int a = 0; a < N; ++a) {
		set<int> sorted_y;
		for (int b = a+1; b < N; ++b) { 
			if (a < b-1) sorted_y.insert(cows[b-1].s);
			int len = cows[b].f-cows[a].f;
			int lo = max(cows[a].s,cows[b].s)-len, hi = min(cows[a].s,cows[b].s); 
			if (lo > hi) continue;
			vector<int> y(begin(sorted_y),end(sorted_y)); 
			int l = 0, r = -1;
			while (l < y.size() && lo >= y[l]+1) l ++; 
			while (r+1 < y.size() && lo >= y[r+1]-len) r ++; 
			while (1) {
				++ ans;
				int yl = min(cows[a].s,cows[b].s), yr = max(cows[a].s,cows[b].s);
				if (l <= r) yl = min(yl,y[l]), yr = max(yr,y[r]);
				assert(yr-yl <= len); 
				eq += yr-yl == len;
				int leave_bottom = (l < y.size() ? y[l]+1 : INT_MAX);
				int enter_top    = (r+1 < y.size() ? y[r+1]-len : INT_MAX);
				int change_y = min(leave_bottom ,enter_top);
				if (change_y > hi) break;
				l += leave_bottom == change_y;
				r += enter_top == change_y;
			}
		}
	}
}
int main() {
	cin >> N; cows.resize(N); 
	for (pi& cow: cows) cin >> cow.f >> cow.s;
	ans = N+1;

	solve();
	for(pi& cow: cows) swap(cow.f,cow.s);
	solve();
	assert(eq%2 == 0);
	cout << ans-eq/2;
}