/*
The 17th Japanese Olympiad in Informatics Final Round Problem 1 
https://oj.uz/problem/view/JOI18_stove
Easy sort and sweep problem
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
int N, K;
ll t[100001];
int main(){
	setIO();
	cin >> N >> K;
	for (int i=0;i<N;i++) cin >> t[i];
	vector<ll> dist;
	for (int i=0;i<N;i++){
		if (i!=0){dist.pb(t[i]-t[i-1]-1);}
	}
	sort(dist.begin(),dist.end(),greater<ll>());
	ll tot = t[N-1]+1-t[0];
	for (int i=0;i<min(N,K-1);i++){
		tot-=dist[i];
	}
	cout << tot << "\n";
}
