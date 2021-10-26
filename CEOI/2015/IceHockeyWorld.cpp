/*
Problem: Central European Olympiad in Informatics 2015 Day 2 bobek
Problem Link: https://oj.uz/problem/view/CEOI15_bobek
Notes: It took me some time to realize that I could split up the values into two sets and use a 
bitmask dp on them. Then I originally used a map and set to count values but I realized I could 
just count the number of sets in O(N) after O(Nlog(N)) sorting.
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
#define int long long
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
ll N, M, c[40];
ll s1[(1<<20)], s2[(1<<20)];
vector<int> v1, v2;
vector<ll> vals;
vector<ll> counts={0};
void setup1(){
	for (int i=1;i<(1<<v1.size());i++){
		for (int j=0;j<v1.size();j++){
			if (i&(1<<j)){
				int n = i&(~(1<<j));
				s1[i]=s1[n]+v1[j];
				break;
			}
		}
	}
}
void setup2(){
	for (int i=1;i<(1<<v2.size());i++){
		for (int j=0;j<v2.size();j++){
			if (i&(1<<j)){
				int n = i&(~(1<<j));
				s2[i]=s2[n]+v2[j];
				break;
			}
		}
	}
}
int32_t main(){
	setIO(); cin >> N >> M; s1[0]=0;s2[0]=0;
	for (int i=0;i<N;i++){cin >> c[i];}
	int h1 = (1<<(N/2)), h2 = (1<<((N+1)/2));
	for (int i=0;i<N/2;i++) v1.pb(c[i]);
	for (int i=N/2;i<N;i++) v2.pb(c[i]);
	setup1();setup2();
	sort(s1,s1+h1);sort(s2,s2+h2);
	ll col = 0, ind = 0;
	for (int i=h1-1;i>=0;i--){
		while (s1[i]+s2[ind]<=M && ind<h2) ind++;
		col+=ind;
	}
	cout << col << "\n";
}
