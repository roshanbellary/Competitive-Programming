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
/*
0-right
1-up
2-left
3-down
*/
struct Post{int x, y;};
struct State{int i, d, dir;};
const int MN = 1e5+2;
int N, dp[MN][4];
Post p[MN];
set<int> xs, ys;
map<int,vector<int>> mx;
map<int,vector<int>> my;
bool sortx(int& i, int& j){return (p[i].y<p[j].y);}
bool sorty(int& i, int& j){return (p[i].x<p[j].x);}
queue<State> q;
int findx(int ind){
    int s = 0, f = mx[p[ind].x].size()-1;
    while (s!=f){
        int mid = (s+f+1)/2;
        if (p[mx[p[ind].x][mid]].y<=p[ind].y) s=mid;
        else f=mid-1;
    }
    return s;
}
int findy(int ind){
    int s = 0, f = my[p[ind].y].size()-1;
    while (s!=f){
        int mid = (s+f+1)/2;
        if (p[my[p[ind].y][mid]].x<=p[ind].x) s=mid;
        else f=mid-1;
    }
    return s;
}
int transform(int ind, int dir){
    int indx = findx(ind);
    int indy = findy(ind);
    if (dir==0){
        if (indy<my[p[ind].y].size()-1) return my[p[ind].y][indy+1];
        else return -1;
    }
    if (dir==1){
        if (indx<mx[p[ind].x].size()-1) return mx[p[ind].x][indx+1];
        else return -1;
    }
    if (dir==2){
        if (indy) return my[p[ind].y][indy-1];
        else return -1;
    }
    if (dir==3){
        if (indx) return mx[p[ind].x][indx-1];
        else return -1;
    }
}
int main(){
	setIO("lasers");rv(N);
    for (int i=0;i<N+2;i++) for (int j=0;j<4;j++) dp[i][j]=1e9;
    for (int i=0;i<N+2;i++) rv(p[i].x,p[i].y), xs.insert(p[i].x), ys.insert(p[i].y);
    for (int i=0;i<N+2;i++) mx[p[i].x].eb(i), my[p[i].y].eb(i);
    for (auto& a:xs) sort(mx[a].begin(),mx[a].end(),sortx);
    for (auto& a:ys) sort(my[a].begin(),my[a].end(),sorty);
    for (int i=0;i<4;i++) q.push({0,0,i}), dp[0][i]=0;
    while (!q.empty()){
        State curr = q.front();q.pop();
        if (dp[curr.i][curr.dir]<curr.d) continue;
        for (int i=0;i<4;i++){
            if (i==(curr.dir+2)%4) continue;
            int ind = transform(curr.i,i);
            if (ind<0) continue;
            if (i!=curr.dir){
                if (dp[ind][i]>curr.d+1){
                    dp[ind][i]=curr.d+1;
                    q.push({ind,dp[ind][i],i});
                }
            }else{
                if (dp[ind][i]>curr.d){
                    dp[ind][i]=curr.d;
                    q.push({ind,dp[ind][i],i});
                }
            }
        }
    }
    int mv = 1e9;
    for (int i=0;i<4;i++) mv=min(mv,dp[1][i]);
    cout << (mv==1e9?-1:mv) << "\n";
}
