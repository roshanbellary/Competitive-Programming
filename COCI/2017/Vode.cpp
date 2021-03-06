/*
Problem: COCI 2017-2018 Round #4 Task: Vode
Problem Link: https://oj.uz/problem/view/COCI17_vode
Notes: It was initially hard for to figure out the transitions for the dp but eventually I was 
able to do it after some debugging.
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
int N, M, K, cn[5000][5001];
int pl[5000], dp[5000][5000];
int main() {
	setIO();cin >> N >> M >> K;
    for (int i=0;i<N;i++) cin >> pl[i];
    for (int i=0;i<N;i++){dp[i][M-1]=!pl[i];cn[i][M]=0;cn[i][M-1]=!pl[i];}
	for (int i = M-2; i >= 0; i--){
		for (int j = 0; j < N; j++){
			int s=i+1,f=min(M,i+K+1),il=f-s,nv=(j+1)%N,itn=cn[nv][s]-cn[nv][f];
			if(pl[j]){
				dp[j][i]=true;
				if(itn==0){
					dp[j][i]=false;
				}
			}else{
				dp[j][i]=false;
				if(itn==il){
					dp[j][i]=true;
				}
			}
			cn[j][i]=cn[j][i+1]+dp[j][i];
		}
	}
	for (int i=0;i<N;i++){
		cout << dp[i][0] << " ";
	}
    cout << "\n";
}
