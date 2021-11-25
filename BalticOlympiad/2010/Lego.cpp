/*
Problem: BOI 2010 Day 1 Lego
Problem Link: https://cses.fi/105/list/
Notes: Really hard dp problem as you have to combine the information of different states of 
legos and find total combinations. Had to use editiorial  to solve problem.
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
char view[6][2][7];
int comb[7][10000],nb[7],H, pos[9],grid[6][6];
ll cnt, np[7][10000];
void setter(int h, int nr, int lx, int ly) {
    int x, y, i,j,k,q,deg;
    char c[9];
    for(x=lx;x<6-1;x++) {
        for(y=(x==lx)?ly+1:0;y<6-1;y++) {
            if(grid[x][y]==-1 && grid[x][y+1]==-1) {
                pos[nr]=x*(6-1)+y;
                grid[x][y]=grid[x+1][y]=grid[x][y+1]=grid[x+1][y+1]=nr;
                setter(h,nr+1,x,y);
                grid[x][y]=grid[x+1][y]=grid[x][y+1]=grid[x+1][y+1]=-1;
            }
        }
    }
    for(i=0;i<nr;i++) c[i]='-';
    for(i=0;i<2;i++) {
        for(j=0;j<6;j++) {
            q=-1;
            for(k=0;k<6;k++) {
                if(i==0) { x=j; y=k;}
                if(i==1) { y=j; x=6-1-k;}
                if(i==2) { x=6-1-j; y=6-1-k;}
                if(i==3) { y=6-1-j; x=k;}
                if(grid[x][y]!=-1) {
                q=grid[x][y];
                break;
                }
            }
            if(q==-1 && view[h][i][j]!='.') return;
            if(q!=-1) {
                if(view[h][i][j]=='.') return;
                if(c[q]=='-') c[q]=view[h][i][j];
                if(c[q]!=view[h][i][j]) return;
            }
        }
    }
    deg=1;
    for(i=0;i<nr;i++) if(c[i]=='-') deg*=3;
    np[h+1][nb[h+1]]=0;
    for(i=0;i<nb[h];i++) {
        for(j=0;j<nr;j++) if(((comb[h][i] >> pos[j]) & 1) == 0) break;
        if(j==nr) {
        np[h+1][nb[h+1]]+=np[h][i]*deg;
        cnt+=np[h][i]*deg;
        }
    }
    if(np[h+1][nb[h+1]]>0) {
        comb[h+1][nb[h+1]]=0;
        for(x=0;x<6-1;x++) for(y=0;y<5;y++) {
            q=x*(5)+y;
            if(grid[x][y]!=-1 || grid[x][y+1]!=-1 || grid[x+1][y]!=-1 || grid[x+1][y+1]!=-1) {
            comb[h+1][nb[h+1]]|=(1<<q);
            }
        }
        nb[h+1]++;
    }
}
int main() {
    setIO();
    int i,j,h;rv(H);
    for(i=0;i<2;i++) for(h=H-1;h>=0;h--) {
        rv(view[h][i]);
        }
    nb[0]=1;
    np[0][0]=1;
    comb[0][0]=~0; 
    for(h=0;h<H;h++) {
        cnt=0;
        for(i=0;i<6;i++) for(j=0;j<6;j++) grid[i][j]=-1;
        setter(h,0,-1,-1);
    }
    cout << cnt << "\n";
}

