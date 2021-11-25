/*
Problem: Squares
Problem Link: https://szkopul.edu.pl/problemset/problem/VeQ6A1Xb8DUSlbUb8eQncsFX/site/?key=statement
Notes: Had to look at editorial to solve problem. Hard dp problem where it was difficult to figure out how the transitions happened and how to have
an efficeint state to store information as 10^18 is a large number.
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
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar_unlocked();
        for (;c>47 && c<58;c=getchar_unlocked()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar_unlocked();
        for (;c>47 && c<58;c=getchar_unlocked()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(string &w){
    w="";char c=getchar_unlocked();
    while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar_unlocked();}
}
inline void rv(char &c){c=getchar_unlocked();}
template<typename T, typename ...Types>
void rv(T &n, Types&&... args){rv(n);rv(args...);}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
const int nums[31] = {128,112,108,96,92,76,72,67,60,48,47,44,43,33,32,31,28,27,24,23,22,19,18,15,12,11,8,7,6,3,2};
int dp[(int)1e4];
ll cn(ll x){return (x * (x + 1) / 2) * (2 * x + 1) / 3;}
int main(){
    setIO();memset(dp,1e9,sizeof(dp));
	for(int i=1; i<=100; i++){
		for(int j=10000; j>=i*i; j--){
			dp[j]=min(dp[j],max(dp[j-i*i],i));
		}
	}
	ll N; rv(N);
	if(N <= 10000){
		int res = 0;
		for(int i=1; i<=N; i++){
			if(dp[i] > 1e8){res++;dp[i] = -1;}
			else{
				if(cn(dp[i] - 1) >= i){
					if(dp[i] >= 20) assert(find(nums, nums + 31, cn(dp[i] - 1) - i) != nums + 31);
					res++;
				}
			}
		}
		if(dp[N] == -1) cout << "-";
		else cout << dp[N];
		cout << "\n";
		return 0;
	}
	ll res = 0;
	for(int i=1; i<=10000; i++){
		if(dp[i] > 1e8) res++;
		if(dp[i] < 20 && cn(dp[i] - 1) >= i) res++;
	}
	int pos = 0, s = 0, e = 2e6;
	while(s != e){
		int m = (s+e)/2;
		if(cn(m) >= N) e = m;
		else s = m + 1;
	}
	pos = s;
	for(int i=20; i<2000000; i++){
        ll cncn = cn(i-1);
        if(cncn > N + 1000) break;
        if(cncn < N - 1000){res += 31;continue;}
		for(int j=0; j<31; j++){
			ll nv = cncn - nums[j];
			if(nv <= N) res++;
			if(nv == N){pos = i;}
		}
	}
	cout << pos << " " << res << endl;
}
