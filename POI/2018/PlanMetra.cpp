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
struct Station{
    int ad, md, ind;  
};
const int MN=1000010;
int N,a[MN],b[MN],id[MN];
struct P{ int x,i; }d[MN];
bool operator <(const P &a,const P &b){ return a.x<b.x; }
int main(){
	setIO();rv(N);
     for (int i=2;i<N-1;i++) rv(a[i]);
     for (int i=2;i<N-1;i++) rv(b[i]);
     if (N==2){ cout << "TAK\n" << "1 2 1\n"; return 0; }
     int len=abs(a[2]-b[2]);
     for (int i=3;i<N-1;i++) if (abs(a[i]-b[i])!=len){ len=0; break; }
     if (len){
         cout << "TAK\n"; cout << N << " " << len << "\n";
         for (int i=2;i<N-1;i++)
             if (a[i]>b[i]) cout << i << " " <<  N << " " << b[i] << "\n";
                 else cout << i << " " << 1 << " " << a[i] << "\n";
         return 0;
     }
     len=2000000; int tot=0;
     for (int i=2;i<N-1;i++) len=min(len,a[i]+b[i]);
     for (int i=2;i<N;i++) if (a[i]+b[i]==len) d[++tot]=(P){a[i],i};
     sort(d+1,d+tot+1); d[0]=(P){0,1}; d[++tot]=(P){len,N};
     for (int i=1;i<tot;i++) if (d[i].x==d[i-1].x){ cout << "NIE\n"; return 0; }
     for (int i=0;i<tot;i++) id[d[i].x]=d[i].i;
     for (int i=2;i<N-1;i++) if (a[i]+b[i]>len && (((a[i]+b[i]-len)&1) || !id[a[i]-(a[i]+b[i]-len)/2])){ cout << "NIE\n"; return 0; }
     cout << "TAK\n";
     for (int i=1;i<tot;i++) printf("%d %d %d\n",d[i-1].i,d[i].i,d[i].x-d[i-1].x);
     for (int i=2;i<N-1;i++) if (a[i]+b[i]>len) printf("%d %d %d\n",id[a[i]-(a[i]+b[i]-len)/2],i,(a[i]+b[i]-len)/2);
     return 0;
}
