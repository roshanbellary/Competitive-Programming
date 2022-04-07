/*
██████╗░░█████╗░██████╗░███████╗██╗░░░░░██╗░░░░░
██╔══██╗██╔══██╗██╔══██╗██╔════╝██║░░░░░██║░░░░░
██████╔╝██║░░██║██████╦╝█████╗░░██║░░░░░██║░░░░░
██╔══██╗██║░░██║██╔══██╗██╔══╝░░██║░░░░░██║░░░░░
██║░░██║╚█████╔╝██████╦╝███████╗███████╗███████╗
╚═╝░░╚═╝░╚════╝░╚═════╝░╚══════╝╚══════╝╚══════╝
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
const int MN = 1e3;
pair<int,int> dir[4]={{1,0},{-1,0},{0,1},{0,-1}};
int N, M, K, dp[MN][MN];
char grid[MN][MN];
vector<pair<int,int>> tel[MN][MN];
struct Edge{int x,y,d;};
queue<Edge> q;
int main(){
	setIO();rv(N, M, K);
    for (int i=0;i<N;i++) fill(dp[i],dp[i]+M,1e9);
    for (int i=0;i<N;i++){
        string s;rv(s);
        for (int j=0;j<M;j++) grid[i][j]=s[j];
    }
    while (K--){
        int x1, y1,x2,y2;rv(x1,y1,x2,y2);
        tel[--x1][--y1].pb({--x2,--y2});
    }
    dp[0][0]=0;q.push({0,0,0});
    while (!q.empty()){
        Edge t = q.front();q.pop();
        if (dp[t.x][t.y]<t.d) continue;
        if (!tel[t.x][t.y].size()){
            for (int i=0;i<4;i++){
                int nx = t.x+dir[i].x, ny=t.y+dir[i].y;
                if (nx<0||nx>=N||ny<0||ny>=M) continue;
                if (dp[nx][ny]>t.d+1 && grid[nx][ny]!='#'){
                    dp[nx][ny]=t.d+1;
                    q.push({nx,ny,t.d+1});
                }
            }
        }else{
            for (auto& a:tel[t.x][t.y]){
                if (dp[a.x][a.y]>t.d && grid[a.x][a.y]!='#'){
                    dp[a.x][a.y]=t.d;
                    q.push({a.x,a.y,t.d});
                }
            }
        }
    }
    cout << dp[N-1][M-1] << "\n";
}
