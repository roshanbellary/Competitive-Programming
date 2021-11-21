/*
Problem:KEYENCE building
Problem Link: https://atcoder.jp/contests/abc227/tasks/abc227_b
Notes: Originally tried a mathematical solution until I realized I could just complete search on all 1,000,000 pairs of (a,b)
for 1<=a,b<=1000 and check if the given number is contained within that set.
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
set<int> v;
int N,s[(int)20];
int main(){
	setIO();cin >> N;
	for (int i=1;i<=1000;i++){
		for (int j=1;j<=1000;j++){
			v.insert(4*i*j+3*i+3*j);
		}
	}
	int num = 0;
	for (int i=0;i<N;i++){
		cin >> s[i];
		if (v.find(s[i])==v.end())num++;
	}
	cout << num << "\n";
}
