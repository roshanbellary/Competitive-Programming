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
struct Edge{
    int o, f, l, i;
    bool operator<(const Edge &a) const{
        return l<a.l;
    }
};
int N, M,d[1500][1500], counts[5000];
vector<Edge> l[1500], el;
vector<int> out(1500,1);
vector<bool> used(5000,0);
void dfs(int ind, int i){
    for (auto e:l[ind]){
        if (d[i][ind]+e.l==d[i][e.f]){
            used[e.i]=1;
            dfs(e.f,i);out[ind]+=out[e.f];
        }
    }
}
int main(){
	setIO();rn(N);rn(M);
    for (int i=0;i<M;i++){
        int O, D, L;rn(O);rn(D);rn(L);
        l[--O].pb({O,--D,L,i});
        el.pb({O,D,L,i});
    }
    for (int i=0;i<N;i++)for (int j=0;j<N;j++) d[i][j]=1e9;
    for (int i=0;i<N;i++){
        priority_queue<Edge> pq;vector<int> num(N,0);
        pq.push({i,i,0,-1});d[i][i]=0;num[i]++;
        while (!pq.empty()){
            Edge n = pq.top();pq.pop();
            n.l*=(-1);if (d[i][n.f]<n.l) continue;
            if (n.i>=0) num[n.f]+=num[n.o];
            for (Edge ne:l[n.f]){
                if (d[i][ne.f]>n.l+ne.l){
                    d[i][ne.f]=n.l+ne.l;
                    pq.push({n.f,ne.f,-(n.l+ne.l),ne.i});
                }
            }
        }
        fill(out.begin(),out.end(),1);
        fill(used.begin(),used.end(),0);dfs(i,i);
        for (int j=0;j<M;j++){
            if (used[j]){
                counts[el[j].i]+=(num[el[j].o]*out[el[j].f]);
                counts[j]%=mod;
            }
        }
    }
    for (int i=0;i<M;i++){
        cout << counts[i] << "\n";
    }
}
