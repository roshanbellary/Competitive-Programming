/*
International Olympiad In Informatics 2008 Contest Day 1 – Type Printer
https://contest.yandex.ru/ioi/contest/567/download/A/
Took me a while to realize I could just use the longest word at the end and count edges 
for the other words.
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
#define mod 1e9+7
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N;
map<string,vector<string>> e;
map<string,bool> m;
string w[(int)25e2];
int edges = 0;
vector<char> ops;
void dfs(string s){
	edges++;
	if (!m[s]){
		ops.pb(s[0]);
		for (string c:e[s]){
			dfs(c);
		}
		if (e[s].size()==0) ops.pb('P');
		ops.pb('-');
	}else{
		ops.pb(s[0]);
		for (string c:e[s]){
			if (!m[c]){
				dfs(c);
			}
		}
		for (string c:e[s]){
			if (m[c]){
				dfs(c);
			}
		}
		if (e[s].size()==0) ops.pb('P');
	}
}
int main(){
	setIO();
	cin >> N;
	int maxl = 0,pos=-1, bp = -1;
	for (int i=0;i<N;i++){
		cin >> w[i];
		if (w[i].length()>maxl){maxl=w[i].length();pos=i;bp=w[i][0]-'a';}
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<w[i].size()-1;j++){
			e[w[i].substr(j,1)+to_string(j)].pb(w[i].substr(j+1,1)+to_string(j+1));
			if (i==pos){
				m[w[i].substr(j,1)+to_string(j)]=true;
				m[w[i].substr(j+1,1)+to_string(j+1)]=true;
			}
		}
	}
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	swap(alpha[bp],alpha[25]);
	for (int i=0;i<alpha.size();i++){
		if (e[alpha.substr(i,1)+"0"].size()==0) continue;
		dfs(alpha.substr(i,1)+"0");
	}
	edges*=2;
	edges-=maxl;
	cout << ++edges<< "\n";
	for (char c:ops){
		cout << c << "\n";
	}
}
