/*
Problem: 
Problem Link: 
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
struct Project{
    int a,b,v;
};
bool sorts(Project &a, Project &b){return (a.b<b.b);}
const int MN = 2e5;
const int MD = 4e5+1;
int N, a[MN], b[MN], p[MN];
ll dp[MD];
vector<int> vals, uni;
vector<Project> v;
int find(int v){
    int s = 0, f=uni.size()-1;
    while (s!=f){
        int mid = (s+f+1)/2;
        if (uni[mid]<=v)s=mid;
        else f=mid-1;
    }
    return (s+1);
}
int main(){
	setIO();rv(N);
	for (int i=0;i<N;i++) rv(a[i],b[i],p[i]),vals.eb(a[i]),vals.eb(b[i]);
    sort(vals.begin(),vals.end());
    for (int i=0;i<vals.size();i++){
        if (uni.size()==0) uni.pb(vals[i]);
        else if (vals[i]==uni.back()) continue;
        else uni.pb(vals[i]);
    }
    for (int i=0;i<N;i++) v.pb({find(a[i]),find(b[i]),p[i]});
    sort(v.begin(),v.end(),sorts);
    dp[0]=0;int ind = 0;ll maxv = 0;
    for (int i=1;i<=MD-1;i++){
        dp[i]=max(dp[i],dp[i-1]);
        while (ind<N){
            if (v[ind].b==i) dp[i]=max(dp[v[ind].a-1]+v[ind].v,dp[v[ind].b]),ind++;
            else break;
        }
        maxv=max(maxv,dp[i]);
    }
    cout << maxv << "\n";
}
