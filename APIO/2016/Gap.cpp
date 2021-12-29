/*
Problem: Gap
Problem Link: https://oj.uz/problem/view/APIO16_gap
Notes: 
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include "gap.h"
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
ll a[100000],j=0;
ll findGap(int T, int N){
    if (T==1) {
		ll l=1,r=1e18;
		ll mn,mx;
		vector<ll> v;
		for (ll i=0;i<(N+1)/2;i++) {
			MinMax(l,r,&mn,&mx);
			a[j++] = mn;
			a[j++] = mx;
			l=mn+1,r=mx-1;
		}
		sort(a,a+N);
		ll ans=0;
		for (ll i=0;i<N-1;i++)ans=max(ans,a[i+1]-a[i]);
		return ans;
	} else {
		ll mn, mx;
		MinMax(1,1e18,&mn,&mx);
		ll step=(mx-mn+N-2)/(N-1);
		ll ans=step,x,y,l=mn,i;
		for (i=mn;i+step<mx;i+=step+1){
			MinMax(i,i+step,&x,&y);
			if(x!=-1){
				ans=max(ans,x-l);
				l=y;
			}
		}
		MinMax(i, mx, &x, &y);
		if (x!=-1)ans=max(ans,x-l);
		return ans;
	}
}
