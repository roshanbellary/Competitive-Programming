/*
Problem: Count The Cows
Problem Link: 
Notes: Super Hard Prob
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
int main(){
	vector<ll> po3{1};
	for (int i = 1; i < 40; ++i) 
		po3.push_back(3*po3.back());
	array<array<array<ll,2>,2>,3> dp, DP;
	int Q; cin >> Q;
	while (Q--) {
		ll d,x,y; cin >> d >> x >> y;
		dp = {}; dp[1][0][0] = 1;
		for (int i=0;i<39;i++) {
			DP = {};
			int dd = d/po3[i]%3, xd = x/po3[i]%3, yd = y/po3[i]%3;
			for (int cmp=0;cmp<3;cmp++) for(int xc=0;xc<2;xc++) for(int yc=0;yc<2;yc++) for(int j=0;j<3;j++) {
				int XD = (xd+xc+j)%3, XC = (xd+xc+j)/3;
				int YD = (yd+yc+j)%3, YC = (yd+yc+j)/3;
				int CMP = cmp;
				if (j > dd) CMP = 2;
				if (j < dd) CMP = 0;
				if (XD%2 == YD%2) DP[CMP][XC][YC] += dp[cmp][xc][yc];
			}
			swap(dp,DP);
		}
		cout << dp[0][0][0]+dp[1][0][0] << "\n";
	}
}
