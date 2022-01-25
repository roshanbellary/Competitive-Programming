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
const int MN = 1000;
struct Seg{double x1, y1, x2, y2;};
struct Point{double x, y;};
int N, C, parent[MN], sizes[MN];
map<pair<double,double>,vector<int>> m;
vector<Seg> poly;
vector<Seg> polygons[MN];
vector<Point> cows;
vector<vector<bool>> col(1000,vector<bool>(1000,0));
int findparent(int i){
    if (i==parent[i]) return i;
    else{parent[i]=findparent(parent[i]);return parent[i];}
}
void unions(int u, int v){
    u=findparent(u);v=findparent(v);
    if (u==v) return;
    if (sizes[v]>sizes[u]) swap(u,v);
    parent[v]=u;sizes[u]+=sizes[v];
}
bool checkIntersect(Seg &a, Seg &b){
    if (b.x1!=b.x2){
        double m2 = (b.y2-b.y1)/(b.x2-b.x1);
        double m1  = (a.y2-a.y1)/(a.x2-a.x1);
        double t1 = (b.y1-a.y1+m2*(a.x1-b.x1))/(m1-m2);
        double t2 = t1+a.x1-b.x1;
        double xc = a.x1+t1; double yc = a.y1+m1*t1;
        bool f1 = (xc>=min(a.x1,a.x2) && xc<=max(a.x1,a.x2) && yc>=min(a.y1,a.y2) && yc<=max(a.y1,a.y2));
        bool f2 = (xc>=min(b.x1,b.x2) && xc<=max(b.x1,b.x2) && yc>=min(b.y1,b.y2) && yc<=max(b.y1,b.y2));
        return (f1&&f2);
    }else{
        if (b.x1>=min(a.x1,a.x2) && b.x1<=max(a.x1,a.x2)){
            double m1 = (a.y2-a.y1)/(a.x2-a.x1);
            double ny = m1*(b.x1-a.x1)+a.y1;
            return (min(b.y1,b.y2)<=ny && max(b.y2,b.y1)>=ny);
        }else return 0;
    }
    return 0;
}
void checkPoint(int ind){
    Seg cs; cs.x1=cows[ind].x;cs.y1=cows[ind].y;
    cs.x2=cows[ind].x+1;cs.y2=cows[ind].y+1e9+1;
    for (int i=0;i<N;i++){
        int sect = 0;
        for (Seg& b:polygons[i]){
            sect+=checkIntersect(cs,b);
        }
        if (sect==1) col[ind][i]=1;
    }
}
int main(){
	setIO("crazy");rv(N, C);
    for (int i=0;i<N;i++) parent[i]=i, sizes[i]=1;
    for (int i=0;i<N;i++){
        Seg n; rv(n.x1,n.y1,n.x2,n.y2);poly.pb(n);
        m[{n.x1,n.y1}].eb(i);
        m[{n.x2,n.y2}].eb(i);
    }
    for (auto& a:m) unions(a.s[0],a.s[1]);
    for (int i=0;i<N;i++) polygons[findparent(i)].eb(poly[i]);
    for (int i=0;i<C;i++){Point c; rv(c.x,c.y);cows.eb(c);}
    for (int i=0;i<C;i++) checkPoint(i);
    map<vector<bool>, int> mr;
    for (int i=0;i<C;i++) mr[col[i]]++;
    int mv = 0;
    for (auto& a:mr) mv=max(mv,a.s);
    cout << mv << "\n";
}
