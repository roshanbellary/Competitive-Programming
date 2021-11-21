/*
Problem: Swap
Problem Link: https://atcoder.jp/contests/abc227/tasks/abc227_e
Notes: Really hard dp problem with complex transitions
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
#define int long long
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
int dp[31][31][31][505];
ll k;
string s;
vector<int>pos[3];
string bb="KEY";
int32_t main(){
	setIO();cin >> s >> k;dp[0][0][0][0] = 1;
	for (int i=0;i<s.size();i++){
        for (int j=0;j<3;j++) if(s[i] == bb[j]) pos[j].pb(i);
	}
	int sz[3]={pos[0].size(),pos[1].size(),pos[2].size()};
	for (int a=0;a<sz[0]+1;a++) for (int b=0;b<sz[1]+1;b++) for (int c=0;c<sz[2]+1;c++){
		for (int d=0;d<505;d++){
			if(dp[a][b][c][d] == 0) continue;
			if(a<sz[0]){
				int cur = pos[0][a], tmp = d;
				for (int i=0;i<b;i++) tmp += pos[1][i] > cur;
				for (int i=0;i<c;i++) tmp += pos[2][i] > cur;
				dp[a+1][b][c][tmp] += dp[a][b][c][d];
			}
			if(b < sz[1]){
				int cur = pos[1][b], tmp = d;
				for (int i=0;i<a;i++) tmp += pos[0][i] > cur;
				for (int i=0;i<c;i++) tmp += pos[2][i] > cur;
				dp[a][b+1][c][tmp] += dp[a][b][c][d];
			}
			if(c < sz[2]){
				int cur = pos[2][c], tmp = d;
				for (int i=0;i<b;i++) tmp += pos[1][i] > cur;
				for (int i=0;i<a;i++) tmp += pos[0][i] > cur;
				dp[a][b][c+1][tmp] += dp[a][b][c][d];
			}
		}
	}
	int ans = 0;
	for(int i=0;i<=min(500LL,k);i++) ans += dp[sz[0]][sz[1]][sz[2]][i];
	cout << ans << "\n";
}