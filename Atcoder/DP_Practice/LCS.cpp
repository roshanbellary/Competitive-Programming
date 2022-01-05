/*
Problem: LCS
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_f
Notes: 
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
string s,t, res="";
int dp[3001][3001];
int main(){
	setIO();
	cin >> s >> t;
	if (s.length()>t.length()) swap(s,t);
	for (int i=1;i<=s.length();i++){
		for (int j=1;j<=t.length();j++){
			if (s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
		}
	}
	int st = s.size(), fi = t.size();
	while (st && fi){
		if (dp[st-1][fi-1]+1==dp[st][fi] && dp[st-1][fi]+1==dp[st][fi] && dp[st][fi-1]+1==dp[st][fi]){
			st--;res=s[st]+res;fi--;
		}else if (dp[st][fi-1]>dp[st-1][fi])  fi--;
		else st--;
	}
	cout << res << "\n";
}
