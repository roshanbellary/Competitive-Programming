/*
USACO 2015 December Contest, Platinum Problem 3. Counting Haybales
http://www.usaco.org/index.php?page=viewproblem2&cpid=578
The problem used a concept which I don't currently understand called lazy propagation for the 
cumulative sum updates. I had it working for regular sum and minimum queries but had to look 
at the editorial to try to understand the cumulative sum queries.
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
int b[1<<19];
int minb[1<<19];
int incre[1<<19];
int a[1<<18];
int qs, qf;
ll minQuery(int l, int r){
	return minQuery(1,0,N-1,l,r);
}
ll sumQuery(int l, int r){
	return sumQuery(1,0,N-1,l,r);
}
void pullUp(int index, int l, int r){
	int mid = (l+r)/2;
	minb[index]=min(minb[2*index]+incre[2*index],minb[2*index+1]+incre[2*index+1]);
	b[index]=(b[2*index] + (r-l+1)*incre[2*index]+b[2*index+1] + (r-l+1)*incre[2*index+1]);
}
void pushDown(int index, int l, int r){
	minb[index] += incre[index];
	b[index] += incre[index] * (r-l+1);
	if(l != r) {
		incre[2*index] += incre[index];
		incre[2*index+1] += incre[index];
	}
	incre[index] = 0;
}
ll minQuery(int index, int l, int r, int left, int right){
	if(r < left || l > right) return 1e18;
	if(l >= left && r <= right) {
		return (minb[index]+incre[index]);
	}
	pushDown(index, l, r);
	int m = (l+r)/2;
	ll ret = 1e18;
	ret = min(ret, minQuery(2*index, l, m, left, right));
	ret = min(ret, minQuery(2*index+1, m+1, r, left, right));
	pullUp(index, l, r);
	return ret;
}
ll sumQuery(int index, int l, int r, int left, int right){
	if(r < left || l > right) return 0;
	if(l >= left && r <= right) {
		return b[index] + (r-l+1)*incre[index];
	}
	pushDown(index, l, r);
	int m = (l+r)/2;
	ll ret = 0;
	ret += sumQuery(2*index, l, m, left, right);
	ret += sumQuery(2*index+1, m+1, r, left, right);
	pullUp(index, l, r);
	return ret;
}
ll queryDist(int node, int start, int end){
	if (start>qf||end<qs) return 0;
	else if ((start>=qs)&&(end<=qf)) return b[node];
	int mid = (start+end)/2;
	return queryDist(2*node,start,mid)+queryDist(2*node+1,mid+1,end);
}
void build(int node, int start, int end){
	if (start==end){
		b[node]=a[start-1];
		minb[node]=a[start-1];
	}else{
		int mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		b[node]=b[2*node]+b[2*node+1];
		minb[node]=min(b[2*node],b[2*node+1]);
	}
}
void update(int index, int l, int r, int left, int right, int inc){
	if(r < left || l > right) return;
	if(l >= left && r <= right) {
		incre[index] += inc;
		return;
	}
	pushDown(index, l, r);
	int m = (l+r)/2;
	update(2*index, l, m, left, right, inc);
	update(2*index+1, m+1, r, left, right, inc);
	pullUp(index, l, r);
}
void update(int l, int r, int inc){
	update(1,0,N-1,l,r,inc);
}
int main(){
	setIO();
	cin >> N >> Q;
	for (int i=0;i<N;i++) cin >> a[i];
	build(1,1,N);
	for (int i=0;i<Q;i++){
		char t; cin >> t;
		int a, b; cin >> a >> b; a--;b--;
		if (t=='P'){
			int c; cin >> c;
			update(a,b,c);
		}else if (t=='M'){
			cout << minQuery(a,b) << "\n";
		}else{
			cout << sumQuery(a,b) << "\n";
		}
	}
}
