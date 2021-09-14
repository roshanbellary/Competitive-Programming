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
int N, Q;
vector<pair<int,int>> points;
vector<pair<int,int>> pos;
vector<pair<int,int>> st;
int calcDist(int i, int j){
	return ((abs(points[i].first-points[j].first))+(abs(points[i].second-points[j].second)));
}
void build(int p, int s, int f){
	if (s>f) return;
	if (s==f){
		if (s<N-1) st[p].second=calcDist(s,s+1)+calcDist(s+1,s+2)-calcDist(s,s+2);
		else st[p].second=0;
		if (s<N) st[p].first=calcDist(s,s+1);
		else st[p].first=0;
		return;
	}
	int mid = (s+f)/2;
	build(2*p,s,mid);
	build(2*p+1,mid+1,f);
	st[p].second=max(st[2*p].second,st[2*p+1].second);
	st[p].first=st[2*p].first+st[2*p+1].first;
}
int getDist(int n, int s, int f, int a, int b){
	if (s>b||f<a) return 0;
	if ((a<=s)&&(b>=f)) return st[n].first;
	int mid=(s+f)/2;
	return getDist(2*n,s,mid,a,b)+getDist(2*n+1,mid+1,f,a,b);
}
int getMax(int n, int s, int f, int a, int b){
	if (s>b||f<a) return 0;
	if ((a<=s)&&(b>=f)) return st[n].second;
	int mid=(s+f)/2;
	return getMax(2*n,s,mid,a,b)+getMax(2*n+1,mid+1,f,a,b);
}
void updateDist(int p, int s, int f, int a, int b){
	if (s>b||f<a) return;
	if ((a<=s)&&(b>=f)){
		if ((s>=1)&&(s<N)) st[p].first=calcDist(s,s+1);
		else st[p].first=0;
		return;
	}
	int mid = (a + b) / 2;
	updateDist(p*2,s,mid,a,b);
	updateDist(p*2+1,mid+1,f,a,b);
	st[p].first=st[2*p].first+st[2*p+1].first;
}
void updateMax(int p, int s, int f, int a, int b){
	if (s>b||f<a) return;
	if ((a<=s)&&(b>=f)){
		if ((s>=1)&&(s<N-1)) st[p].second=calcDist(a,a+1)+calcDist(a+1,a+2)-calcDist(a,a+2);
		else st[p].second=0;
		return;
	}
	int mid = (a + b) / 2;
	updateMax(p*2,s,mid,a,b);
	updateMax(p*2+1,mid+1,f,a,b);
	st[p].second=max(st[2*p].second,st[2*p+1].second);
}
int main(){
	setIO();
	cin >> N >> Q;
	points.pb({0,0});
	for (int i=0;i<N;i++){
		int x,y; cin >> x >> y;
		points.pb({x,y});
	}
	for (int i=0;i<2*N+1;i++){
		st.pb({0,0});
	}
	build(1,1,N);
	for (int i=0;i<Q;i++){
		char t; cin >> t;
		if (t=='Q'){
			int s, f; cin >> s >> f;
			f--;
			int d = getDist(1,1,N,s,f);
			f--;
			int maxi = getMax(1,1,N,s,f);
			cout << d-maxi << "\n";
		}else{
			int ind, x, y; cin >> ind >> x >> y;
			for (int j=ind-1;j<=ind;j++){
				updateDist(1,1,N,j,j);
			}
			for (int j=ind-2;j<=ind;j++){
				updateMax(1,1,N,j,j);
			}
		}
	}
}
