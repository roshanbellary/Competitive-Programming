/*
Problem: Multiplayer Moo
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=836
Notes: Not complete yet. Haven't implemented compression of connected components part
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
const int MN = 250;
int N, grid[MN][MN],sizes[MN][MN],S=0;
bool v[MN][MN];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int comp1 = 0, comp2 = 0;
map<int,int> m;
void dfs(int x, int y){
    v[x][y]=1;S++;
    for (int i=0;i<4;i++){
        int nx = x+dx[i],ny=y+dy[i];
        if (nx<0||nx>=N||ny<0||ny>=N) continue;
        if (v[nx][ny]||grid[nx][ny]!=grid[x][y]) continue;
        dfs(nx,ny);
    }
}
void clear(){for (int i=0;i<N;i++) for (int j=0;j<N;j++) v[i][j]=0;}
void setSize(int x, int y, int n){
    v[x][y]=1;sizes[x][y]=n;
    for (int i=0;i<4;i++){
        int nx = x+dx[i],ny=y+dy[i];
        if (nx<0||nx>=N||ny<0||ny>=N) continue;
        if (v[nx][ny]||grid[nx][ny]!=grid[x][y]) continue;
        setSize(nx,ny,n);
    }
}
void findSize2(int x, int y){
    v[x][y]=1;
    for (int i=0;i<4;i++){
        int nx = x+dx[i],ny=y+dy[i];
        if (nx<0||nx>=N||ny<0||ny>=N) continue;
        if (grid[nx][ny]!=grid[x][y]){m[grid[nx][ny]]+=sizes[nx][ny];comp2=max(m[grid[nx][ny]]+sizes[x][y],comp2);}
        else if (!v[nx][ny]) findSize2(nx,ny);
    }
}
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) rv(grid[i][j]);
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (!v[i][j]){
                S=0;dfs(i,j);
                sizes[i][j]=S;
            }
        }
    }
    clear();
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (sizes[i][j]>0){
                comp1=max(comp1,sizes[i][j]);
                setSize(i,j,sizes[i][j]);
            }
        }
    }
    clear();
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (!v[i][j]){
                m.clear();
                findSize2(i,j);
            }
        }
    }
    cout << comp1 << " " << comp2 << "\n";
}
