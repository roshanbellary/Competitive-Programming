/*
██████╗░░█████╗░██████╗░███████╗██╗░░░░░██╗░░░░░
██╔══██╗██╔══██╗██╔══██╗██╔════╝██║░░░░░██║░░░░░
██████╔╝██║░░██║██████╦╝█████╗░░██║░░░░░██║░░░░░
██╔══██╗██║░░██║██╔══██╗██╔══╝░░██║░░░░░██║░░░░░
██║░░██║╚█████╔╝██████╦╝███████╗███████╗███████╗
╚═╝░░╚═╝░╚════╝░╚═════╝░╚══════╝╚══════╝╚══════╝
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
int w[3], h[3];
ll res = 0;
vector<vector<int>> g(3,vector<int>(3,0));
void start(int r, int p){
    if (p!=2){
        for (int i=1;i<=min(h[r],w[p])-2;i++){
            g[r][p]=i;
            start(r,p+1);
            g[r][p]=0;
        }
    }else{
        g[r][2]=h[r]-g[r][0]-g[r][1];
        if (g[r][2]<=0){g[r][2]=0; return;}
        if (r==2){
            bool work = 1;
            for (int i=0;i<3;i++){
                int sum=0;
                for (int j=0;j<3;j++){
                    sum+=g[j][i];
                }
                if (sum!=w[i]) work=0;
            }
            if (work) res++;
        }else start(r+1,0);
        g[r][p]=0;
    }
}
int main(){
	setIO();
    for (int i=0;i<3;i++) rv(h[i]);
    for (int i=0;i<3;i++) rv(w[i]);
    start(0,0);
    cout << res << "\n";
}
