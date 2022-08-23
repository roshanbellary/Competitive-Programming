/*
██████╗░░█████╗░██████╗░███████╗██╗░░░░░██╗░░░░░
██╔══██╗██╔══██╗██╔══██╗██╔════╝██║░░░░░██║░░░░░
██████╔╝██║░░██║██████╦╝█████╗░░██║░░░░░██║░░░░░
██╔══██╗██║░░██║██╔══██╗██╔══╝░░██║░░░░░██║░░░░░
██║░░██║╚█████╔╝██████╦╝███████╗███████╗███████╗
╚═╝░░╚═╝░╚════╝░╚═════╝░╚══════╝╚══════╝╚══════╝
Problem: Planet Queries 2
Problem Link: https://cses.fi/problemset/task/1160
Notes: 
Definitely hard problem
Have to break up into 3 cases
Case #1: A & B lie on same loop
Explanation:
    Basically find all loops in graph and assign the following information to each
    vertice in the loops, a loop position number and a loop identification number.
    These 2 bits of information let us see if 2 vertices exist in the same loop
    and if so how far away they are.
Case #2: A lies in tree, B lies in loop. The ancestor of A lies in same loop as B
Explanation:
    Keep track of all loop vertices that have trees hanging off them. For each of these vertices
    run a dfs to keep track of depth information then do some bit lifting, record the 2^nth ancestor where n<=20
    for each vertice that lies in the tree including the loop vertex. Then to check if A has an ancestor that lies
    in the same loop as B, use the largest ancestor of A and check its loop identification number to see if it matches
    the loop id of B if so then B is reachable from A and using the loop position number of As ancestor and B along with As
    depth information we can find the distance from A to B
Case #3: A & B lie in same tree
Explanation:
    Using the bit lifting we did for each tree, determine if depth[A]>=depth[B].
    If so then using the difference depth[A]-depth[B], find the depth[A]-depth[B] ancestor of A
    using bit lifting. If that ancestor is equal to B then we're done and the answer is depth[A]-depth[B].
    If not then the answer is -1
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
const int MN = 2e5;
int N, Q, loop[MN], loop_pos[MN], t[MN], vis[MN], depth[MN], ancestor[MN][20];
vector<int> rt[MN];
stack<int> path;
vector<vector<int>> loops;
vector<int> traverse;
vector<int> origin_pts;
void dfs(int i, int mark){
    vis[i]=mark;path.push(i);
    if (vis[t[i]]==0){
        dfs(t[i],mark);
    }else if (vis[t[i]]==mark && !loop[t[i]]){
        loops.eb(vector<int>());
        while (path.size()){
            if (path.top()!=t[i]){
                loops.back().eb(path.top());path.pop();
            }else break;
        }
        loops.back().eb(t[i]);
        reverse(loops.back().begin(), loops.back().end());
        for (int j=0;j<loops.back().size();j++){
            loop_pos[loops.back()[j]]=j;
            loop[loops.back()[j]]=loops.size();
        }
    }
}
void dfs2(int i, int parent, int d){
    traverse.eb(i);
    depth[i]=d; ancestor[i][0]=parent;
    for (int& j:rt[i]) if (!loop[j]) dfs2(j,i, d+1);
}
int main(){
	setIO();rv(N, Q);
    fill(loop,loop+N,0);
    for (int i=0;i<N;i++) rv(t[i]),t[i]--, rt[t[i]].eb(i);
    int count=1;
    for (int i=0;i<N;i++){
        if (vis[i]==0) dfs(i,count++);
        while (path.size()) path.pop();
    }
    for (int i=0;i<N;i++){
        if (loop[i]){
            bool origin = 0;
            for (int& j:rt[i]){
                if (!loop[j]) origin=1;
            }
            if (origin) origin_pts.eb(i);
        }
    }
    for (int& i:origin_pts){
        dfs2(i, i, 0);
        for (int j=1;j<20;j++){
            for (int& k:traverse) ancestor[k][j]=ancestor[ancestor[k][j-1]][j-1];
        }
        traverse.clear();
    }
    while (Q--){
        int a, b;rv(a,b);
        a--;b--;
        if (a==b){cout << "0\n"; continue;}
        if (loop[a]>0 && loop[b]>0){
            if (loop[a]==loop[b]){
                cout << (loop_pos[b]-loop_pos[a]>0?loop_pos[b]-loop_pos[a]:loop_pos[b]-loop_pos[a]+loops[loop[a]-1].size()) << "\n";
            } else cout << "-1\n";
        }else if (loop[b]){
            if (loop[b]==loop[ancestor[a][19]]){
                int diff = loop_pos[b]-loop_pos[ancestor[a][19]];
                cout << depth[a]+(diff>=0?diff:diff+loops[loop[b]-1].size()) << "\n";
            }else cout << "-1\n";
        }else if (loop[a]){
            cout << "-1\n";
        } 
        else if (ancestor[a][19]==ancestor[b][19] && depth[a]>=depth[b]){
            int diff = depth[a]-depth[b];
            int curr = a;
            for (int j=19;j>=0;j--) if (diff&(1<<j)) curr=ancestor[curr][j];
            if (curr==b) cout << diff << "\n";
            else cout << "-1\n";
        }else cout << "-1\n";
    }
}
