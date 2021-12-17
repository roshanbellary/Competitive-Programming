/*
Problem: Haybale Stacking
Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=104
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
void rv(T &n, Types&&... args){rv(n);rv(args...);}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
struct Add{
    int p, t;
};
bool sorts(Add &a, Add &b){return a.p<b.p;}
int N, K;
vector<Add> st;
vector<Add> pal;
vector<pair<int,int>> vals;
int main(){
	setIO("stacking");rv(N, K);
    while (K--){
        int s, f; rv(s,f);
        st.pb({s,1});
        if (f<N) st.pb({++f,-1});
    }
    sort(st.begin(),st.end(),sorts);
    for (int i=0;i<st.size();i++){
        int j=i+1;
        while (j<st.size()){
            if (st[j].p==st[i].p){
                st[i].t+=st[j].t;j++;
            }else{
                break;
            }
        }
        pal.pb(st[i]);i=j-1;
    }
    int curr = 1, v = 0;
    for (auto &e:pal){
        vals.pb({v,e.p-curr});
        v+=e.t;curr=e.p;
    }
    if (curr<=N) vals.pb({v,N-curr+1});
    sort(vals.begin(),vals.end());
    int pales = 0, ind = 0;
    while (true){
        pales+=vals[ind].s;
        if (pales>=(N+1)/2){
            cout << vals[ind].f << "\n";
            break;
        }
        ind++;
    }
}
