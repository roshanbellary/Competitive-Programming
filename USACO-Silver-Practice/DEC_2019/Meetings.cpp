/*
Problem: Meetings
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=967
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
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar();
        for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar();
        for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(string &w){
    w="";char c=getchar();
    while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar();}
}
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
const int MN = 5e4;
struct Cow{
	ll w,x,d,g;
	bool operator<(Cow &n){
		if (n.x==x) return n.x>x;
		return n.x>x;
	}
};
struct Event{
	ll t, w;
	bool operator<(Event &n){
		return n.t>t;
	}
};
ll N, L,W=0;
Cow f[MN];
vector<ll> l,r;
vector<pair<ll,ll>> lt;
vector<Event> tl;
int main(){
	setIO("meetings");rv(N, L);
	for (int i=0;i<N;i++){rv(f[i].w,f[i].x,f[i].d);W+=f[i].w;}
	sort(f,f+N);
	for (int i=0;i<N;i++){
		if (f[i].d<0) l.pb(i);
		else r.pb(i);
	}
	for (int i=0;i<l.size();i++) tl.pb({f[l[i]].x,f[i].w});
	for (int i=r.size()-1;i>=0;i--) tl.pb({L-f[r[i]].x,f[N-1-(r.size()-1-i)].w});
	sort(tl.begin(),tl.end());
	ll col = 0, T = 0;
	for (int i=0;i<tl.size();i++){
		int j=i+1, tcol = tl[i].w;
		while (j<tl.size()){
			if (tl[j].t==tl[i].t) j++,tcol+=tl[j].w;
			else break;
		}
		col+=tcol;
		if (col>=(W+1)/2){T=tl[i].t;break;}
		i=j-1;
	}
	ll left = 0, right = 0;
	for (int i=N-1;i>=0;i--){
		if (f[i].d<0) left++;
		else right++;
		if (f[i].d>0) f[i].g=left;
	}
	for (int i=0;i<N;i++){
		f[i].x+=(f[i].d*T);
	}
	sort(f,f+N);
	ll meets = 0;left=0;right=0;
	for (int i=N-1;i>=0;i--){
		if (f[i].d<0) left++;
		else right++;
		if (f[i].d>0) meets+=(f[i].g-left);
	}
	cout << meets << "\n";
}
