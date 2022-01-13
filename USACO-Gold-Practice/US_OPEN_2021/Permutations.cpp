/*
Problem: Permutations
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
using P = pair<int,int>;
using Tri = array<int,3>;
struct mi {
 	int v; explicit operator int() const { return v; } 
	mi() { v = 0; }
	mi(ll _v):v(_v%mod) { v += (v<0)*mod; }
};
vector<mi> dp[100][100][100];
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= mod) a.v -= mod; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += mod; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
int N;
vector<P> points;
 
P& operator-=(P& a, const P& b) {
	a.f -= b.f, a.s -= b.s;
	return a;
}
int cross(P a, P b, P c) {
	b -= a; c -= a;
	return b.f*c.s-b.s*c.f;
}
 
int area(Tri a) {
	return abs(cross(points[a[0]],points[a[1]],points[a[2]]));
}
 
bool inside(Tri a, int b) {
	int sum = 0;
	for (int i = 0; i < 3; ++i) {
		swap(a[i],b);
		sum += area(a);
		swap(a[i],b);
	}
	sum -= area(a); assert(sum >= 0);
	return sum == 0;
}
 
void ad(vector<mi>& v, int ind, mi val) {
	while (v.size() <= ind) v.push_back(0);
	v[ind]+=val;
}
 
int main() {
	cin >> N; points.resize(N); 
	for (P& p: points) cin >> p.f >> p.s;

	vector<Tri> triangles;
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
			for (int k = j+1; k < N; ++k)
				triangles.push_back({i,j,k});
	sort(begin(triangles),end(triangles),[&](Tri a, Tri b) {
		return area(a) < area(b); });

	mi ans = 0;
	for (Tri& t: triangles) {
		int tot_inside = 0;
		vector<Tri> nex;
		for (int i = 0; i < N; ++i) {
			if (inside(t,i)) ++tot_inside;
			else {
				for (int j = 0; j < 3; ++j) {
					Tri new_t = t; new_t[j] = i;
					sort(begin(new_t),end(new_t));
					if (inside(new_t,t[j])) 
						nex.push_back(new_t);
				}
			}
		}
		tot_inside -= 3;
		assert(tot_inside >= 0);
		dp[t[0]][t[1]][t[2]].resize(1+tot_inside);
		dp[t[0]][t[1]][t[2]][0] = 1;
		for (int i = 0; i <= tot_inside; ++i) {
			mi v = dp[t[0]][t[1]][t[2]][i];
			if (i < tot_inside)
				ad(dp[t[0]][t[1]][t[2]],1+i,(tot_inside-i)*v.v);
			for (Tri u: nex)
				ad(dp[u[0]][u[1]][u[2]],1+i,v);
		}
		if (tot_inside == N-3) 
			ans += dp[t[0]][t[1]][t[2]][tot_inside];
	}
	cout << (6*(ans.v)) << "\n";
}
