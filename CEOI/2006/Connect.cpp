/*
Problem: Connect
Problem Link: https://cses.fi/file/2a3333c827a59499bbbc1c16a74e8c8b29a5d1f3371bb088997da772dd1352d7
Notes: Really Really hard dp problem
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
int R, C,tdist[25][80];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int dp[2000][2];
char grid[25][80];
vector<pair<int,int>> st;
map<pair<int,int>, int> m;
vector<vector<int>> dist;
struct Point{
    int x, y, d;
};
void clearGrid(){
    for (int i=0;i<R;i++) for (int j=0;j<C;j++) tdist[i][j]=1e9;
}
void setDist(int ind){
    clearGrid();
    queue<Point> q;tdist[st[ind].f][st[ind].s]=0;
    q.push({st[ind].f,st[ind].s,0});
    while (!q.empty()){
        Point e = q.front();q.pop();
        if (tdist[e.x][e.y]<e.d) continue;e.d++;
        for (int i=0;i<4;i++){
            int nx = e.x+dx[i], ny = e.y+dy[i];
            if (nx<0||nx>=R||ny<0||ny>=C) continue;
            if (grid[nx][ny]=='+'||grid[nx][ny]=='|'||grid[nx][ny]=='-') continue;
            if (tdist[nx][ny]<=e.d) continue;
            tdist[nx][ny]=e.d;
            if (tdist[nx][ny]=='X') dist[ind][m[{nx,ny}]]=e.d;
            q.push({nx,ny,e.d});
        }
    }
}
int main(){
	setIO();rv(R, C);
    for (int i=0;i<R;i++){
        string s; rv(s);for (int j=0;j<C;j++) grid[i][j]=s[j];
    }
    int c = 0;
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            if (grid[i][j]=='X'){st.pb({i,j}),m[{i,j}]=c;}
        }
    }
    for (int i=0;i<c;i++) dist.pb(vector<int>(c,1e9));
    for (int i=0;i<c;i++) setDist(i);
    set<int> s;
    for (int i=0;i<c;i++){
        setDist(i);
    }
    for (int i=0;i<c;i++){
        for (int j=0;j<c;j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
