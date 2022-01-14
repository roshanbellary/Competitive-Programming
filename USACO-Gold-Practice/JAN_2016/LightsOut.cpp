/*
Problem: Lights Out
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=599
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
// Need orientation and distance of segment
// Path is an alternating of angle direction and distances
const int MN = 200;
int N, ld[MN], rd[MN], d[MN];
vector<pair<int,int>> poly, seg, tpath;
vector<bool> dir;
void setMinDist(){
    ld[0]=0;
    for (int i=1;i<N;i++){
        ld[i]=ld[i-1]+abs(poly[i].f-poly[i-1].f)+abs(poly[i].s-poly[i-1].s);
    }
    rd[N-1]=abs(poly[0].f-poly[N-1].f)+abs(poly[N-1].s-poly[0].s);
    for (int i=N-2;i>=0;i--){
        rd[i]=rd[i+1]+abs(poly[i].f-poly[i+1].f)+abs(poly[i].s-poly[i+1].s);
    }
    for (int i=0;i<N;i++) d[i]=min(ld[i],rd[i]);
}
void setEdges(){
    for (int i=0;i<N;i++){
        int j=(i+1)%N;seg.pb({poly[j].f-poly[i].f,poly[j].s-poly[i].s});
    }
}
void findDir(){
    for (int i=0;i<seg.size();i++){
        int j = (i+1)%N;
        int b1, b2;
        if (seg[j].s==0){
            if (seg[j].f>0) b2=0;// x increase
            else b2=1;// x decrease
        }else{
            if (seg[j].s>0) b2=2;// y increase
            else b2=3; // y decrease
        }
        if (seg[i].s==0){
            if (seg[i].f>0) b1=0;// x increase
            else b1=1;// x decrease
        }else{
            if (seg[i].s>0) b1=2; // y increase
            else b1=3;// y decrease
        }
        if ((b1==0 && b2==2) || (b1==1 && b2 == 3)) dir.pb(0);
        else dir.pb(1);
    }
}
bool recognize(vector<pair<int,int>> &path){
    int rec = 0;
    for (int i=2;i<tpath.size();i+=2){
        int s = i, d=path.size(), cd=0;
        bool ndiff = 1;
        while (d--){
            if (tpath[s]==path[cd]){s++;s%=tpath.size();}
            else{ndiff=0;break;}
            cd++;
        }
        rec+=ndiff;
    }
    return (rec<=1);
}
int main(){
	setIO("lightsout");rv(N);
    for (int i=0;i<N;i++){int x, y; rv(x,y);poly.pb({x,y});}
    setMinDist();setEdges();findDir();
    for (int i=0;i<N;i++){tpath.pb(seg[i]);tpath.pb({dir[i],1e9});}
    int maxv = 0;
    for (int i=1;i<N;i++){
        vector<pair<int,int>> cpath;
        int j=i, tcol = (abs(seg[j].f)+abs(seg[j].s));
        cpath.pb({seg[j]});cpath.pb({dir[j],1e9});j++;j%=N;
        while (j!=0){
            if (recognize(cpath)) break;
            cpath.pb({seg[j]});cpath.pb({dir[j],1e9});tcol+=(abs(seg[j].f)+abs(seg[j].s));
            j++;j%=N;
        }
        tcol+=d[j];
        maxv=max(maxv,tcol-d[i]);
    }
    cout << maxv << "\n";
}
