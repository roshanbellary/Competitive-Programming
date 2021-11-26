/*
Problem: Slikar
Problem Link: https://dmoj.ca/problem/coci08c4p4
Notes: Long dp problem involving minimization of different slices of the grid. In order to print out the optimal solution I just stored which pieces
of a subgrid were colored in which way ie efficiently or all black or all white then constructed my solution from there.
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
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar_unlocked();
        for (;c>47 && c<58;c=getchar_unlocked()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar_unlocked();
        for (;c>47 && c<58;c=getchar_unlocked()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(string &w){
    w="";char c=getchar_unlocked();
    while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar_unlocked();}
}
inline void rv(char &c){c=getchar_unlocked();}
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
struct State{
    int f1, f2, w, b;
};
int N, dp[512][512][10],bp[1<<9+1][1<<9+1],wp[1<<9+1][1<<9+1],col[512][512];
bool g[1<<9][1<<9];
State opt[1<<9][1<<9][10];
int findsimb(int i, int j, int d){
    int fi = i+(1<<d)-1,fj = j+(1<<d)-1,sim = bp[fi][fj];
    if (i) sim-=bp[i-1][fj];if (j) sim-=bp[fi][j-1];if (i&&j) sim+=bp[i-1][j-1];
    return ((1<<d)*(1<<d)-sim);
}
int findsimw(int i, int j, int d){
    int fi = i+(1<<d)-1, fj = j+(1<<d)-1,sim = wp[fi][fj];
    if (i) sim-=wp[i-1][fj];if (j) sim-=wp[fi][j-1];if (i&&j) sim+=wp[i-1][j-1];
    return ((1<<d)*(1<<d)-sim);
}
void findmins(int i, int j, int d){
    int xs[4] = {i,i+1<<(d-1),i,i+1<<(d-1)},ys[4] = {j,j,j+1<<(d-1),j+1<<(d-1)},col[1<<9][1<<9];
    if (d==0){dp[i][j][d]=0;return;}
    for (int a=0;a<4;a++){
        if (dp[xs[a]][ys[a]][d-1]==1e9) findmins(xs[a],ys[a],d-1);
    }
    set<int> s = {0,1,2,3};
    for (int a=0;a<4;a++){
        s.erase(a);
        for (int b=a+1;b<4;b++){
            s.erase(b);
            int fb, sb;fb=*s.begin(),sb=*s.rbegin();
            if (dp[i][j][d]>findsimb(xs[fb],ys[fb],d-1)+findsimw(xs[sb],ys[sb],d-1)+dp[xs[a]][ys[a]][d-1]+dp[xs[b]][ys[b]][d-1]){
                dp[i][j][d]=findsimb(xs[fb],ys[fb],d-1)+findsimw(xs[sb],ys[sb],d-1)+dp[xs[a]][ys[a]][d-1]+dp[xs[b]][ys[b]][d-1];
                opt[i][j][d]={a,b,sb,fb};
            }
            if (dp[i][j][d]>findsimw(xs[fb],ys[fb],d-1)+findsimb(xs[sb],ys[sb],d-1)+dp[xs[a]][ys[a]][d-1]+dp[xs[b]][ys[b]][d-1]){
                dp[i][j][d]=findsimw(xs[fb],ys[fb],d-1)+findsimb(xs[sb],ys[sb],d-1)+dp[xs[a]][ys[a]][d-1]+dp[xs[b]][ys[b]][d-1];
                opt[i][j][d]={a,b,fb,sb};
            }
            s.insert(b);
        }
        s.insert(a);
    }
}
void fills(int i, int j, int d, int c){
    for (int a=i;a<i+1<<d;a++) for (int b=j;b<j+1<<d;b++) col[a][b]=c;
}
void dfs(int i, int j, int d){
    int xs[4] = {i,i+1<<(d-1),i,i+1<<(d-1)},ys[4] = {j,j,j+1<<(d-1),j+1<<(d-1)};
    if (d==0) col[i][j]=g[i][j];
    else{
        fills(xs[opt[i][j][d].w],ys[opt[i][j][d].w],d-1,0);
        fills(xs[opt[i][j][d].b],ys[opt[i][j][d].b],d-1,1);
        dfs(xs[opt[i][j][d].f1],ys[opt[i][j][d].f1],d-1);
        dfs(xs[opt[i][j][d].f2],ys[opt[i][j][d].f2],d-1);
    }
}
int main(){
	setIO();cin >> N;
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) for (int d=0;d<=log2(N);d++) dp[i][j][d]=1e9;
    for (int i=0;i<N;i++){
        string s;cin >> s;
        for (int j=0;j<N;j++) g[i][j]=(s[j]=='1');
    }
    for (int i=0;i<N;i++){for (int j=0;j<N;j++){if (g[i][j]) bp[i][j]=1;else bp[i][j]=0;}}
    for (int i=0;i<N;i++){for (int j=0;j<N;j++){if (!g[i][j]) wp[i][j]=1;else wp[i][j]=0;}}
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (i) wp[i][j]+=wp[i-1][j];
            if (j) wp[i][j]+=wp[i][j-1];
            if (i&&j) wp[i][j]-=wp[i-1][j-1];
            if (i) bp[i][j]+=bp[i-1][j];
            if (j) bp[i][j]+=bp[i][j-1];
            if (i&&j) bp[i][j]-=bp[i-1][j-1];
        }
    }
    findmins(0,0,(int)log2(N));
    cout << dp[0][0][(int)log2(N)] << "\n";
    dfs(0,0,log2(N));
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout << col[i][j];
        }
        cout << "\n";
    }
}
