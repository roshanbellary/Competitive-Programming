/*
Problem: Blocking The View
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
struct Point{ll x,y;};
struct Vec{
    ll x, y;
};
bool onSegment(Point& p, Point& q, Point& r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
ll orientation(Point& p, Point& q, Point& r)
{
    ll val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
bool doIntersect(Point& p1, Point& q1, Point& p2, Point& q2)
{
    ll o1 = orientation(p1, q1, p2);
    ll o2 = orientation(p1, q1, q2);
    ll o3 = orientation(p2, q2, p1);
    ll o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4) return 1;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return 0;
}
bool solve(){
    Point a1, a2, b1,b2;Vec v;
    rv(a1.x,a1.y,a2.x,a2.y,b1.x,b1.y,b2.x,b2.y,v.x,v.y);
    Point e1, e2, e3,e4;
    e1=a1;e2=a2;e3=b1;e4=b2;
    ll m = 0;
    if (v.x==0) m=(2e6/abs(v.y)+1);
    else if (v.y==0) m=(2e6/abs(v.x)+1);
    else m=max((2e6/abs(v.x)+1),(2e6/abs(v.y)+1));
    e1.x+=m*(v.x);
    e1.y+=m*(v.y);
    e2.x+=m*(v.x);
    e2.y+=m*(v.y);
    e3.x-=m*(v.x);
    e3.y-=m*(v.y);
    e4.x-=m*(v.x);
    e4.y-=m*(v.y);
    if (doIntersect(a1,e1,b1,b2)) return 1;
    if (doIntersect(a2,e2,b1,b2)) return 1;
    if (doIntersect(b1,e3,a1,a2)) return 1;
    if (doIntersect(b2,e4,a1,a2)) return 1;
    return 0;
}
int T;
int main(){
	setIO();rv(T);
    while (T--) cout << (solve()?"Yes":"No") << "\n";
}
