/*Note: I barely passed this problem as test case 15 had 0.99s run time.
The only reason I passed was by using the below fast IO optimization with excessive use of getchar()
which has faster runtime than cin. After looking at the Hacking tab in CSES after I solved the problem,
I found that a far faster method to solve was to include the edges into the distance array as you read them in
that way you don't deal with the extra overhead of an adjacency list as you can iterate over all possible triples from getting from one point to the other
TLDR:Fast input saves your life even if you have the wrong algorithm lmao
*/
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
int N, M, Q;
ll d[500][500];
bool v[500][500];
vector<pair<int,ll>> l[(int)500];
int main(){
	setIO();rn(N);rn(M);rn(Q);
    for (int i=0;i<M;i++){
        int a, b, c; rn(a);rn(b);rn(c);
        l[--a].pb({--b,c});l[b].pb({a,c});
    }
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) d[i][j]=1e18;
    for (int i=0;i<N;i++){
        d[i][i]=0;
        while (true){
            int minp = -1;ll mind = 1e18;
            for (int j=0;j<N;j++){
                if (!v[i][j]&&mind>d[i][j]){
                    minp=j;mind=d[i][j];
                }
            }
            if (minp<0) break;v[i][minp]=1;
            for (pair<int,ll> e:l[minp]){
                d[i][e.f]=min(d[i][e.f],e.s+d[i][minp]);
            }
        }
    }
    for (int i=0;i<Q;i++){
        int u, v; rn(u);rn(v);
        cout << ((d[--u][--v]==1e18)?-1:d[u][v]) << "\n";
    }
}
