/*
Problem:LCS on Permutations
Problem Link: https://codeforces.com/gym/102951/problem/C
Notes: Longest Increasing Subsequence prob. I need to start using the multiset insertion and deletion method
more often and getting a good handle on it.
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
int N, a[MN], b[MN], dp[MN], p[MN], m[MN];
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++) rv(a[i]);
    for (int i=0;i<N;i++) rv(b[i]), p[b[i]-1]=i;
    for (int i=0;i<N;i++) m[i]=p[a[i]-1];
    set<pair<int,int>> s;
    for (int i=N-1;i>=0;i--){
        auto itr = s.upper_bound({m[i],-1});
        if (itr==s.end()){
            dp[i]=1;s.insert({m[i],dp[i]});
        }else{
            dp[i]=itr->s+1;
            if (itr==s.begin()){
                s.insert({m[i],dp[i]});
            }else{
                auto itr2 = itr;
                while (itr2!=s.begin()){
                    if (itr2->s<=dp[i]) itr2--;
                    else break;
                }
                if (itr2->s<=dp[i]) s.erase(itr2,itr);
                else{itr2++;s.erase(itr2,itr);}
                s.insert({m[i],dp[i]});
            }
        }
    }
    int MV = 0;
    for (int i=0;i<N;i++) MV=max(MV,dp[i]);
    cout << MV << "\n";
}
