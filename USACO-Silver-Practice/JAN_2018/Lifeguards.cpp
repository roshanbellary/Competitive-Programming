/*
Problem: Lifeguards
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=786
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
const int MN = 1e5;
class Guard{
    public:
        int s,o, ind;
        bool t;
};
vector<Guard> g;
int N, d[MN], S = 0;
bool sorts(Guard &a, Guard &b){return a.s<b.s;}
int main(){
	setIO("lifeguards");rv(N);
    for (int i=0;i<N;i++){
        int s, f;rv(s,f);
        g.pb({s,f,i,1});g.pb({f,s,i,0});
    }
    sort(g.begin(),g.end(),sorts);
    int active=0,s=-1,f=-1;
    for (auto &e:g){
        if (e.t){
            if (active>0) S+=(e.s-s);
            s=e.s;active++;
        }else{
            S+=(e.s-s);s=e.s;active--;
        }
    }
    set<int> inds;
    for (auto &e:g){
        if (e.t){
            if (inds.size()==1) d[*inds.begin()]+=(e.s-s);
            s=e.s;inds.insert(e.ind);
        }else{
            if (inds.size()==1) d[*inds.begin()]+=(e.s-s);
            s=e.s;inds.erase(e.ind);
        }
    }
    int maxV = 0;
    for (int i=0;i<N;i++){
        maxV=max(S-d[i],maxV);
    }
    cout << maxV << "\n";
}
