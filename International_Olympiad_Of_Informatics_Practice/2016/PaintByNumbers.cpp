/*
Problem: IOI 2016 Day 2 Problem 1 Paint By Numbers
Problem Link: https://oj.uz/problem/view/IOI16_paint
Notes: Really hard dp problem, so I had to look at the editorial
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
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar_unlocked();
        for (;c>47 && c<58;c=getchar_unlocked()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar_unlocked();
    if (c=='-'){m=-1; c=getchar_unlocked();}
    for (;c>47 && c<58;c=getchar_unlocked()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar_unlocked();
        for (;c>47 && c<58;c=getchar_unlocked()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(string &w){
    w="";char c=getchar_unlocked();
    while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar_unlocked();}
}
inline void rv(char &c){c=getchar_unlocked();}
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
int N, K;
string ans, ss;
vector<int> C;
int p[200000], p2[200000], a[200000][2], dp[200000][101];
bool recur(int pos, int num){
    if(dp[pos][num]!=-1) return dp[pos][num];
    if(pos==N) return dp[pos][num]=(num==K);
    bool op1=false, op2=false;
    if(num==K){
        int cnt = p2[N]-p2[pos];
        if(cnt) return false;
        op2 = recur(pos+1, num);
        if(op2) a[pos][0] = 1;
        return dp[pos][num]=true;
    }
    int cnt = C.at(num);
    if(ss[pos]=='_'){
        if(ss[pos]=='X') return dp[pos][num]=false;
        op2 = recur(pos+1, num);
    }
    else if(ss[pos]=='X'){
        if(num!=K-1){
            if(pos+cnt<N and p[pos+cnt]==p[pos])
                if(p2[pos+cnt+1]==p2[pos+cnt])
                    op1 = recur(pos+cnt+1, num+1);
        }
        else{
            if(pos+cnt<=N and p[pos+cnt]==p[pos])
                op1 = recur(pos+cnt, num+1);
        }
    }
    else{
        if(num!=K-1){
            if(pos+cnt<N and p[pos+cnt]==p[pos])
                if(p2[pos+cnt+1]==p2[pos+cnt])
                    op1 = recur(pos+cnt+1, num+1);
        }
        else{
            if(pos+cnt<=N and p[pos+cnt]==p[pos])
                op1 = recur(pos+cnt, num+1);
        }
        op2 = recur(pos+1, num);
    }
    if(op1){
        a[pos][1]++, a[pos+cnt][1]--;
        if(num!=K-1) a[pos+cnt][0] = 1;
    }
    if(op2) a[pos][0] = 1;
    return dp[pos][num]=(op1||op2);
}
 
string solve_puzzle(string s, vector<int> c){
    N = (int)s.size(),K=(int)c.size();
    ss = s, C = c, p[0]=p2[0]=0;
    for(int i=0;i<N;i++)
        p[i+1] = p[i]+(s[i]=='_'?1:0),
        p2[i+1] = p2[i]+(s[i]=='X'?1:0);
    memset(dp, -1, sizeof(dp)), recur(0, 0);
    for(int i=0;i<N;i++){
        a[i+1][1]+=a[i][1];
        if(a[i][1] and a[i][0]) ans+='?';
        else if(a[i][1]) ans+='X';
        else ans+='_';
    }
    return ans;
}
