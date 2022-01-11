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
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
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
const int MN = 4e5+1;
int N, b[MN], ft[MN], fw[MN], bw[MN], curr[MN];
ll res = 0;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int query(int i){return (i?ft[i]+query(i-(i&(-i))):0);}
void update(int i, int v){
    while (i<MN){
        ft[i]+=v;i+=(i&(-i));
    }
}
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++) rv(b[i]),b[i]--, curr[i]=-1;
    for (int i=N-1;i>=0;i--){
        if (curr[b[i]]<0) fw[i]=2e5;
        else fw[i]=curr[b[i]]-i;
        curr[b[i]]=i;
    }
    for (int i=0;i<N;i++) curr[i]=-1;
    for (int i=0;i<N;i++){
        if (curr[b[i]]<0) bw[i]=2e5;
        else bw[i]=i-curr[b[i]];
        curr[b[i]]=i;
    }
    for (int i=0;i<N;i++){
        while (!pq.empty()){
            if (pq.top().f<=i){
                update(pq.top().s+1,-1);
                pq.pop();
            }else break;
        }
        if (i-bw[i]+1<0) res+=query(MN-1);
        else res+=(query(MN-1)-query(i-bw[i]+1));
        pq.push({i+fw[i],i});
        update(i+1,1);
    }
    cout << res << "\n";
}
