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
const int MN = 1e5;
int N, v[MN], dp[MN], c[MN];
pair<int,int> range[MN];
vector<int> dist;
set<int> met, fin;
stack<int> col;
bool check(){
    for (int& j:dist){// check for broken ranges that are broken up by 0s
        if (j==0){
            for (int k:met){fin.insert(k);met.clear();}
            continue;
        }
        if (fin.find(j)!=fin.end()) return 0;
        else if (met.find(j)!=met.end()) fin.insert(j);
        else met.insert(j);
    }
    met.clear();
    for (int& j:dist){
        if (j==0) continue;
        if (range[j-1].f==range[j-1].s) continue;
        if (met.find(j)!=met.end()){// checks if all ranges are nested and do not intersect
            if (col.top()!=j) return 0;
            else col.pop();
        }else{
            if (range[j-1].f!=range[j-1].s) met.insert(j), col.push(j);
        }
    }
    return 1;
}
int main(){
	setIO("art2");rv(N);
    for (int i=0;i<N;i++) rv(v[i]);
    for (int i=0;i<N;i++){
        int j=i+1;
        while (j<N){
            if (v[i]==v[j]) j++;
            else break;
        }
        dist.eb(v[i]);i=j-1;
    }
    bool t = check();
    if (!t){cout << "-1\n";return 0;}
    int mv = 1;met.clear();
    for (int i=0;i<dist.size();i++){
        if (dist[i]==0) continue;
        if (range[dist[i]-1].f==range[dist[i]-1].s) continue;
        int open = 1,j;
        for (j=i+1;j<dist.size();j++){
            if (dist[j]==dist[i]) break;
            if (range[dist[j]-1].f==range[dist[j]-1].s) mv=max(open+1,mv);
            else if (met.find(dist[j]-1)!=met.end()) open--;
            else{mv=max(++open,mv);met.insert(dist[j]-1);}
             mv=max(open,mv);
        }
        i=j;open=0;
    }
    cout << mv << "\n";
}
