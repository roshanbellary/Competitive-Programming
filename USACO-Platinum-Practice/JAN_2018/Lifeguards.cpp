/*
Problem: USACO 2018 January Contest, Platinum Problem 1. Lifeguards
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=792
Notes: I didn't realize I could use two points along with dynamic programming to solve the 
problem to make the unions of ranges.
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
struct Guard{
    int s,f;
};
bool sorts(Guard &a, Guard &b){return a.s<b.s;}
Guard g[(int)1e5];
int N, K,dp[(int)1e5][2];
int main(){
	setIO();cin >> N >> K;
    for (int i=0;i<N;i++){
        cin >> g[i].s >> g[i].f;
    }
    sort(g,g+N,sorts);
    for (int i=0;i<N;i++){
        dp[i][0]=g[i].f-g[i].s;
    }
    while (--K){
        int ml = 1e9;
        set<pair<int,int>> in;
        set<pair<int,int>> out;
        priority_queue<pair<int,int>> tout;
        priority_queue<pair<int,int>> tin;
        for (int i=0;i<N;i++){
            while (tout.size()>0){
                pair<int,int> t = tout.top();
                if (-t.f<g[i].f){
                    in.insert({dp[t.s][0]+g[t.s].f,t.s});tin.push({-g[t.s].f,t.s});
                    out.erase(out.find({dp[t.s][0],t.s}));tout.pop();
                }else{
                    break;
                }
            }
            while (tin.size()>0){
                pair<int,int> t = tin.top();
                if (-t.f<g[i].s){
                    in.erase(in.find({dp[t.s][0]+g[t.s].f,t.s}));tin.pop();
                    ml=max(dp[t.s][0],ml);
                }else{
                    break;
                }
            }
            if (out.size()>0) dp[i][1]=max(dp[i][1],out.begin()->first);
            if (in.size()>0) dp[i][1]=max(dp[i][1],in.begin()->first-g[i].s);
            dp[i][1]=max(dp[i][1],ml+g[i].f-g[i].s);
            out.insert({dp[i][0],i});tout.push({-g[i].f,i});
        }
        for (int i=0;i<N;i++){
            swap(dp[i][0],dp[i][1]);
            dp[i][1]=1e9;
        }
    }
    int maxv = 1e9;
    for (int i=0;i<N;i++){
        maxv=max(maxv,dp[i][0]);
    }
    cout << maxv << "\n";
}
