/*
Problem: Do You Know Your ABCs?
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=1135
Notes: Really cool recursion problem
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
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar();
        for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar();
        for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(string &w){
    w="";char c=getchar();
    while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar();}
}
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
int T,N;
vector<int> n;
set<int> diff;
int solve(){
    n.clear();diff.clear();
    rv(N);for (int i=0;i<N;i++){int v; rv(v);n.pb(v);}
    n.pb(0);
    sort(n.begin(),n.end());
    for (int i=0;i<=N;i++){
        for (int j=i+1;j<=N;j++){
           diff.insert(n[j]-n[i]); 
        }
    }
    int num = 0;
    for (int a:diff){
        for (int b:diff){
            for (int c:diff){
                if (!(1<=a && a<=b && b<=c)) continue;
                set<int> pos = {a,b,c,a+b,b+c,a+c,a+b+c};
                bool w = 1;
                for (int i=1;i<=N;i++){
                    if (pos.find(n[i])==pos.end()){
                        w=0;break;
                    }
                }
                num+=w;
            }
        }
    }
    return num;
}
int main(){
	setIO();rv(T);
    while (T--){
        cout << solve() << "\n";
    }
}
