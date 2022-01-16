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
/*
4 directions:
0-left
1-up
2-right
3-down

Transitions:
left = {0,-1}
up = {-1,0}
right = {0,1}
down = {1,0}

Rotations:
++ = turn right
-- = turn left
*/
struct State{int d1, d2, x1, y1, x2, y2, d;};
const int MN = 20, MD = 4;
int N, dp[MD][MD][MN][MN][MN][MN];
char g[MN][MN];
pair<int,int> dir[4]={{0,-1},{-1,0},{0,1},{1,0}};
queue<State> q;
void setdp(){
    for (int a=0;a<MD;a++)
        for (int b=0;b<MD;b++)
            for (int c=0;c<MN;c++)
                for (int d=0;d<MN;d++)
                    for (int e=0;e<MN;e++)
                        for (int f=0;f<MN;f++) dp[a][b][c][d][e][f]=1e9;
}
pair<int,int> transform(int d, int x, int y){
    if (x==N-1 && y==N-1) return make_pair(x,y);
    int nx = dir[d].f+x, ny = dir[d].s+y;
    if (nx<0 || nx>=N || ny<0||ny>=N) return make_pair(x,y);
    if (g[nx][ny]=='H') return make_pair(x,y);
    return make_pair(nx,ny);
}
int main(){
	setIO("cownav");setdp();rv(N);
    for (int i=0;i<N;i++){
        string s;rv(s);
        for (int j=0;j<N;j++) g[i][j]=s[j];
    }
    dp[2][3][0][0][0][0]=0;
    q.push({2,3,0,0,0,0,0});
    while (!q.empty()){
        State curr = q.front();q.pop();
        if (dp[curr.d1][curr.d2][curr.x1][curr.y1][curr.x2][curr.y2]<curr.d) continue;
        pair<int,int> nc1 = transform(curr.d1,curr.x1,curr.y1);
        int nx1 = nc1.f, ny1 = nc1.s;
        pair<int,int> nc2 = transform(curr.d2,curr.x2,curr.y2);
        int nx2 = nc2.f, ny2 = nc2.s;
        if (dp[curr.d1][curr.d2][nx1][ny1][nx2][ny2]>curr.d+1){
            dp[curr.d1][curr.d2][nx1][ny1][nx2][ny2]=curr.d+1;
            q.push({curr.d1,curr.d2,nx1,ny1,nx2,ny2,curr.d+1});
        }
        //Turn Right
        int nd1 = curr.d1, nd2=curr.d2;
        if (curr.x1!=N-1 || curr.y1!=N-1) nd1=(curr.d1+1)%MD;
        if (curr.x2!=N-1 || curr.y2!=N-1) nd2=(curr.d2+1)%MD;
        if (dp[nd1][nd2][curr.x1][curr.y1][curr.x2][curr.y2]>curr.d+1){
            dp[nd1][nd2][curr.x1][curr.y1][curr.x2][curr.y2]=curr.d+1;
            q.push({nd1,nd2,curr.x1,curr.y1,curr.x2,curr.y2,curr.d+1});
        }
        //Turn Left
        nd1 = curr.d1, nd2=curr.d2;
        if (curr.x1!=N-1 || curr.y1!=N-1) nd1 = (curr.d1-1+MD)%MD;
        if (curr.x2!=N-1 || curr.y2!=N-1) nd2 = (curr.d2-1+MD)%MD;
        if (dp[nd1][nd2][curr.x1][curr.y1][curr.x2][curr.y2]>curr.d+1){
            dp[nd1][nd2][curr.x1][curr.y1][curr.x2][curr.y2]=curr.d+1;
            q.push({nd1,nd2,curr.x1,curr.y1,curr.x2,curr.y2,curr.d+1});
        }
    }
    int minv = 1e9;
    for (int i=0;i<MD;i++) for (int j=0;j<MD;j++) minv=min(dp[i][j][N-1][N-1][N-1][N-1],minv);
    cout << minv << "\n";
}
