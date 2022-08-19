/*
Problem: Taming
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
const int MN = 101;
int N,n[MN],d[MN];
bool v[MN];
int main(){
	setIO("taming");rv(N);
    memset(d,-1,sizeof(d));
    for (int i=0;i<N;i++) rv(n[i]);
    for (int i=0;i<N;i++){
        if (n[i]<0) continue;
        if (i-n[i]<0){cout << "-1\n";return 0;}
    }
    v[0]=1;
    for (int i=0;i<N;i++){
        if (n[i]<0) continue;
        v[i-n[i]]=1;
    }
    int r = 0;
    for (int i=0;i<N;i++){
        if (v[i]) r=i;
        if (n[i]<0) continue;
        if (n[i]!=i-r){cout << "-1\n";return 0;}
    }
    int minV = 0;
    for (int i=0;i<N;i++) minV+=v[i];
    for (int i=0;i<N;i++){
        for (int j=i-n[i];j<=i;j++){
            d[j]=(j-(i-n[i]));
        }
    }
    int maxV=minV;
    d[0]=0;
    for (int i=0;i<N;i++){
        if (d[i]<0) maxV++;
    }
    cout << minV << " " << maxV << "\n";
}
