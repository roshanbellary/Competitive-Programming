/*
Problem: COCI 2017/2018 ROUND 5 January 20th Task: Karte
Problem Link: https://oj.uz/problem/view/COCI18_karte
Notes: I kept on running into some weird compiler error, but after some googling I was able to 
resolve the error and finish the problem
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
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N, K, a[(int)5e5];
int main(){
   	setIO();
	cin >> N >> K;
	for (int i=0;i<N;i++) cin >> a[i];
	int z = 0;
	for (int i=0;i<N;i++){
		if (!a[i]) z++;
	}
	sort(a,a+N);
	if (N-z<K) cout << "-1\n";
	else if (z==N && !K){
		for (int i=0;i<N;i++) cout << "0 ";
		cout << "\n";
	}else if (!K){
		cout << "-1\n";
	}else{
		vector<int> n;
		for (int i=N-K;i<N;i++){
			n.pb(a[i]);
		}
		for (int i=0;i<N-K;i++){
			n.pb(a[i]);
		}
		int check = 0;
		for (int i=0;i<N;i++){
			if (check<n[i]) check++;
		}
		if (check!=K) cout << "-1\n";
		else{
			reverse(n.begin(),n.end());
			for (int i=0;i<N;i++) cout << n[i] << " ";
			cout << "\n";
		}
	}
}
