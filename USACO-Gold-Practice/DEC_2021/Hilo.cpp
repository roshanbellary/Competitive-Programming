/*
Problem: HILO
Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=1161
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
const int MN = 2e5+1;
int N, p[MN], prevs[MN];
bool hilo[MN];
stack<int> s;
int main(){
	setIO();rv(N);
    for (int i=1;i<=N;i++) {
        int pr;rv(pr);p[pr] = i;
    }
    s.push(0);
    for (int i=N;i>0;i--) {
        while (s.top()>p[i]) s.pop();
        prevs[p[i]] = s.top();
        s.push(p[i]);
    }
    while (s.size() != 1) s.pop();
    cout << "0\n";
    int count = 0;
    for (int i=1;i<=N;i++) {
        while (s.top() > p[i]) {
            count -= hilo[s.top()];
            s.pop();
        }
        if (prevs[p[i]]!=0 && (s.top()==0 || prevs[p[i]]!=prevs[s.top()])) hilo[p[i]]=1;
        else hilo[p[i]]=0;
        s.push(p[i]);
        count += hilo[p[i]];
        cout << count << "\n";
    }
    return 0;
}
