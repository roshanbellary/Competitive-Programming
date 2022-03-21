/*
██████╗░░█████╗░██████╗░███████╗██╗░░░░░██╗░░░░░
██╔══██╗██╔══██╗██╔══██╗██╔════╝██║░░░░░██║░░░░░
██████╔╝██║░░██║██████╦╝█████╗░░██║░░░░░██║░░░░░
██╔══██╗██║░░██║██╔══██╗██╔══╝░░██║░░░░░██║░░░░░
██║░░██║╚█████╔╝██████╦╝███████╗███████╗███████╗
╚═╝░░╚═╝░╚════╝░╚═════╝░╚══════╝╚══════╝╚══════╝
Problem: Nearest Excluded Points
Problem Link: https://codeforces.com/contest/1651/problem/D
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
#define x first
#define y second
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
inline void rv(char &c){c=' ';while (c==' '|| c=='\n' || c==EOF) c=getchar();}
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
const int MN = 2e5;
int N, d[MN];
pair<int,int> pts[MN], res[MN], dir[4]={{1,0},{0,1},{-1,0},{0,-1}};
map<pair<int,int>,int> ex;
queue<pair<int,int>> q;
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++) rv(pts[i].x,pts[i].y), ex[{pts[i].x,pts[i].y}]=i+1;
    fill(d,d+N,1e9);
    for (int i=0;i<N;i++){
        int ct = 0, dirs = -1;
        for (int j=0;j<4;j++){
            int r = ex[{pts[i].x+dir[j].x,pts[i].y+dir[j].y}];
            ct+=(r>0);
            if (r==0) dirs=j;
        }
        if (ct<4){
            d[i]=1;q.push({i,1}); 
            res[i]={pts[i].x+dir[dirs].x,pts[i].y+dir[dirs].y};
        }
    }
    while (!q.empty()){
        pair<int,int> ed = q.front();q.pop();
        if (d[ed.x]<ed.y) continue;
        for (int i=0;i<4;i++){
            int r = ex[{pts[ed.x].x+dir[i].x,pts[ed.x].y+dir[i].y}];
            if (r--){
                if (d[r]>ed.y+1){
                    d[r]=ed.y+1;res[r]=res[ed.x];
                    q.push({r,ed.y+1});
                }
            }
        }
    }
    for (int i=0;i<N;i++){
        cout << res[i].x << " " << res[i].y << "\n";
    }
}
