/*
Problem: Just One
Problem Link: https://atcoder.jp/contests/abc226/tasks/abc226_e
Notes: 
First notice that the ways to make the directed edges for each connected component compound upon each other.
Let us take an abitrary connected component G1 in G and let E(G1) be the number of edges and V(G1) be the number of vertices
if E(G1)<V(G1) then there are 0 ways to direct the edges as the graph is a tree and by induction the bottom of the tree must have one directed 
edge and so on until we reach the root of the tree which has no edges to make directed

Now if E(G1)=V(G1) then there are 2 ways to direct the edges. This is evident as we can find a spanning tree of the connected component. 
For the spanning tree if we add an edge anywhere then we form a cycle with two trees spawning from it. These two trees have only one way to direct their edges
while the cycle has two different orientations giving us 2 ways to direct a cycle of N edges and N vertices

Now if E(G1)>V(G1) then there are 0 ways to direct the edges. This is true as those E(G1) edges have to be distributed among the V(G1) vertices to set their origin.
However by pidgeonhole at least one vertex must have more than 1 directed edge which it is the origin of which means the graph cannot be directed properly
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
int mod=998244353;
template <class T> 
void rn(T &n){
    n=0;int m = 1;int c;
    c = getchar();if (c=='-') m=-1;
    for (;c>47 && c<58;c=getchar()){
        n=n*(1<<1)+n*(1<<3)+c-48;
    }
    n*=m;
}
void rw(string &w){
    w="";char c=getchar();
    while (c!=' '&&c!='\n'&&c!=EOF){
        w+=c;c=getchar();
    }
}
void rc(char &c){
	c=getchar();
}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N, M, sc=0, se=0;
vector<int> l[(int)2e5];
bool v[(int)2e5];
void dfs(int i){
    v[i]=1;sc++;se+=l[i].size();
    for (int j:l[i]){
        if (!v[j]) dfs(j);
    }
}
int main(){
	setIO();rn(N); rn(M);
    for (int i=0;i<M;i++){
        int u, v; rn(u);rn(v);u--;v--;
        l[u].eb(v);l[v].eb(u);
    }
    ll res = 1;
    for (int i=0;i<N;i++){
        if (!v[i]){
            sc=0,se=0;dfs(i);
            if (se%2==1){
                res=0;
            }else if (sc==se/2){res*=2;res%=mod;}
            else res=0;
        }
    }
    cout << res << "\n";
}
