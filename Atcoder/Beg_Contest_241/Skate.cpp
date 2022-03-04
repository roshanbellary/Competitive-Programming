/*
██████╗░░█████╗░██████╗░███████╗██╗░░░░░██╗░░░░░
██╔══██╗██╔══██╗██╔══██╗██╔════╝██║░░░░░██║░░░░░
██████╔╝██║░░██║██████╦╝█████╗░░██║░░░░░██║░░░░░
██╔══██╗██║░░██║██╔══██╗██╔══╝░░██║░░░░░██║░░░░░
██║░░██║╚█████╔╝██████╦╝███████╗███████╗███████╗
╚═╝░░╚═╝░╚════╝░╚═════╝░╚══════╝╚══════╝╚══════╝
Problem: Skate
Problem Link: https://atcoder.jp/contests/abc241/tasks/abc241_f
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
struct Loc{
    int x, y, i;
    bool operator==(Loc& u){
        return (i==u.i);
    }
};
struct Reach{Loc l;int d, dir;};
const int MN = 1e5+2;
int H, W, N, d[MN][5];
Loc p[MN];
Loc fi;
map<int,vector<Loc>> mx, my;
bool sorty(Loc& a, Loc&b){return (a.y<b.y);}
bool sortx(Loc& a, Loc&b){return (a.x<b.x);}
queue<Reach> q;
void findnext(Reach a){
    int ix = 0, iy=0;
    for (;ix<mx[a.l.x].size();ix++){
        if (mx[a.l.x][ix].y>a.l.y) break;
    }
    for (;iy<my[a.l.y].size();iy++){
        if (my[a.l.y][iy].x>a.l.x) break;
    }
    if (a.dir!=1 && ix){
        ix--;
        if (!(mx[a.l.x][ix]==a.l)){
            Loc l = mx[a.l.x][ix];
            if (d[l.i][1]>a.d+1){
                d[l.i][1]=a.d+1;
                q.push({{l.x,l.y+1,l.i},a.d+1,1});
            }
        }else if (ix){
            Loc l = mx[a.l.x][ix-1];
            if (d[l.i][1]>a.d+1){
                d[l.i][1]=a.d+1;
                q.push({{l.x,l.y+1,l.i},a.d+1,1});
            }
        }
    }
    if (a.dir!=2 && ix<mx[a.l.x].size()){
        Loc l = mx[a.l.x][ix];
        if (d[l.i][2]>a.d+1){
            d[l.i][2]=a.d+1;
            q.push({{l.x,l.y-1,l.i},a.d+1,2});
        }
    }
    if (a.dir!=3 && iy){
        iy--;
        if (!(my[a.l.y][iy]==a.l)){
            Loc l = my[a.l.y][iy];
            if (d[l.i][3]>a.d+1){
                d[l.i][3]=a.d+1;
                q.push({{l.x+1,l.y,l.i},a.d+1,3});
            }
        }else if (iy){
            Loc l = my[a.l.y][iy-1];
            if (d[l.i][3]>a.d+1){
                d[l.i][3]=a.d+1;
                q.push({{l.x+1,l.y,l.i},a.d+1,3});
            }
        }
    }
    if (a.dir!=4 && iy<my[a.l.y].size()){
        Loc l = my[a.l.y][iy];
        if (d[l.i][4]>a.d+1){
            d[l.i][4]=a.d+1;
            q.push({{l.x-1,l.y,l.i},a.d+1,4});
        }
    }
}
int main(){
	setIO();rv(H, W, N);
    for (int i=0;i<N+2;i++) for (int j=0;j<5;j++) d[i][j]=1e9;
    rv(p[0].x,p[0].y);p[0].i=0;
    rv(fi.x,fi.y);
    for (int i=1;i<N+1;i++) rv(p[i].x,p[i].y), p[i].i=i, mx[p[i].x].eb(p[i]), my[p[i].y].eb(p[i]);
    for (auto a:mx) sort(a.y.begin(),a.y.end(),sorty);
    for (auto a:my) sort(a.y.begin(),a.y.end(),sortx);
    q.push({p[0],0,0});d[0][0]=0;
    while (!q.empty()){
        Reach e = q.front();q.pop();
        if (d[e.l.i][e.dir]<e.d) continue;
        findnext(e);
    }
    int minv = 1e9;
    for (int i=0;i<N+1;i++){
        if (fi.x==p[i].x){
            if (fi.y==p[i].y-1){
                minv=min(d[i][2],minv);
            }else if (fi.y==p[i].y+1){
                minv=min(d[i][1],minv);
            }
        }else if (fi.y==p[i].y){
            if (fi.x==p[i].x-1){
                minv=min(d[i][4],minv);
            }else if (fi.x==p[i].x+1){
                minv=min(d[i][3],minv);
            }
        }
    }
    cout << (minv==1e9?-1:minv) << "\n";
}
