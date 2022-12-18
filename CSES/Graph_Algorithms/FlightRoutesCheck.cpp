/*
██████╗░░█████╗░██████╗░███████╗██╗░░░░░██╗░░░░░
██╔══██╗██╔══██╗██╔══██╗██╔════╝██║░░░░░██║░░░░░
██████╔╝██║░░██║██████╦╝█████╗░░██║░░░░░██║░░░░░
██╔══██╗██║░░██║██╔══██╗██╔══╝░░██║░░░░░██║░░░░░
██║░░██║╚█████╔╝██████╦╝███████╗███████╗███████╗
╚═╝░░╚═╝░╚════╝░╚═════╝░╚══════╝╚══════╝╚══════╝
Problem: Flight Routes Check
Problem Link: https://cses.fi/problemset/task/1682
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
const int MN = 1e5;
int N, M, vis[MN], vis2[MN], C=0, comp[MN], rep[MN];
vector<int> l[MN], rl[MN], tsort;
set<int> dg[MN];
void dfs(int i){
    vis[i]=1;
    for (int& j:rl[i]){
        if (!vis[j]){
            dfs(j);
        }
    }
    tsort.eb(i);
}
void dfs2(int i, int c){
    vis2[i]=1; comp[i]=c;
    for (int& j:l[i]){
        if (!vis2[j]){
            dfs2(j,c);
        }
    }
}
int main(){
	setIO();rv(N, M);C=N;
    while (M--){
        int a, b; rv(a,b);
        l[--a].eb(--b);
        rl[b].eb(a);
    }
    for (int i=0;i<N;i++) if (!vis[i]) dfs(i);
    C=0;
    for (int i=tsort.size()-1;i>=0;i--){
        if (!vis2[i]) dfs2(i,C++);
    }
    cout << (C==1?"YES":"NO") << "\n";
    if (C!=1){
        for (int i=0;i<N;i++){
            for (int& j:l[i]){
                if (comp[j]!=comp[i]){
                    dg[comp[i]].insert(comp[j]);
                }
            }
        }
        for (int i=0;i<N;i++) rep[comp[i]]=i;
        for (int i=0;i<C;i++){
            if (dg[i].size()>0){
                cout << rep[(*dg[i].begin())]+1 << " " << rep[i]+1 << "\n";
                break;
            }
        }
    }
    
}
