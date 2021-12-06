/*
Problem: Multiplayer Moo
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=836
Notes:Super Freaking long problem. Main thing to realize here is that you 
can think of the different connected components graphically. Draw edges between
neighboring components and set the colors for how you will go across components and from there
you can figure out the size of a component of 2 colors
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
int N, grid[MN][MN],sizes[MN][MN],comps[MN][MN],cc[62500],sc[62500],S=0,C=0;
bool v[MN][MN];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int comp1 = 0, comp2 = 0;
set<int> l[62500],col[62500], dist;
map<int,int> m;
map<int,pair<int,int>> fc;
void clear(){for (int i=0;i<N;i++) for (int j=0;j<N;j++) v[i][j]=0;}
void findSize(int x, int y){
    v[x][y]=1;S++;
    for (int i=0;i<4;i++){
        int nx = x+dx[i],ny=y+dy[i];
        if (nx<0||nx>=N||ny<0||ny>=N) continue;
        if (v[nx][ny]||grid[nx][ny]!=grid[x][y]) continue;
        findSize(nx,ny);
    }
}
void findSize(){
    clear();
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (!v[i][j]){
                S=0;findSize(i,j);
                sizes[i][j]=S;
                comp1=max(comp1,S);
            }
        }
    }
}
void setComps(int x, int y, int c){
    v[x][y]=1;comps[x][y]=c;
    for (int i=0;i<4;i++){
        int nx = x+dx[i],ny=y+dy[i];
        if (nx<0||nx>=N||ny<0||ny>=N) continue;
        if (v[nx][ny]||grid[nx][ny]!=grid[x][y]) continue;
        setComps(nx,ny,c);
    }
}
void mapComps(){
    clear();
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (sizes[i][j]>0){
                fc[C]={i,j};sc[C]=sizes[i][j];
                cc[C]=grid[i][j];setComps(i,j,C++);
            }
        }
    }
}
void setList(int x, int y, int c){
    v[x][y]=1;
    for (int i=0;i<4;i++){
        int nx = x+dx[i],ny=y+dy[i];
        if (nx<0||nx>=N||ny<0||ny>=N) continue;
        if (grid[nx][ny]!=grid[x][y]){
            l[c].insert(comps[nx][ny]);
            col[c].insert(cc[comps[nx][ny]]);
        }else if (!v[nx][ny]){
            setList(nx,ny,c);
        }
    }
}
void setList(){
    clear();
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (sizes[i][j]>0){
                setList(i,j,comps[i][j]);
            }
        }
    }
}
void findcols(int i, int c1, int c2){
    dist.insert(i);
    for (int j:l[i]){
        if (dist.find(j)!=dist.end()) continue;
        if (cc[j]==c1 || cc[j]==c2){
            findcols(j,c1,c2);
        }
    }
}
void calcComp2(){
    for (int i=0;i<C;i++){
        for (int c:col[i]){
            dist.clear();
            findcols(i,cc[i],c);
            int sizec = 0;
            for (int k:dist){sizec+=sc[k];}
            comp2=max(comp2,sizec);
        }
    }
}
int main(){
	setIO("multimoo");rv(N);
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) rv(grid[i][j]);
    findSize();mapComps();
    setList();calcComp2();
    cout << comp1 << "\n" << comp2 << "\n";
}
