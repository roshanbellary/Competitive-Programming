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
int mod=1e9+7;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int M;
vector<int> l[9];
int dp[362880];
map<string,int> m;
map<int,string> rm;
char n[9]; bool a[9];
int main(){
	for (int i=0;i<362880;i++) dp[i]=1e9;
	setIO(); cin >> M;
	string s = "123456789"; int p = 0;
	do{
		rm[p]=s;
		m[s]=p++;
	}while(next_permutation(s.begin(),s.end()));
	for (int i=0;i<M;i++){
		int u,v; cin >> u >> v;
		l[--u].pb(--v);
		l[v].pb(u);
	}
	for (int i=0;i<8;i++){
		int num; cin >> num; a[num-1]=true;
		n[num-1]=(to_string(i+1))[0];
	}
	for (int i=0;i<9;i++){
		if (!a[i]){
			n[i]='9';
		}
	}
	string word = "";
	for (int i=0;i<9;i++) word+=n[i];
	int cp = m[word];
	queue<pair<int,int>> q;
	q.push({cp,0});
	dp[cp]=0;
	while (!q.empty()){
		int pos = q.front().first;
		int d = q.front().second;
		q.pop();
		if (dp[pos]<d) continue;
		string w = rm[pos];
		for (int i=0;i<9;i++){
			if (w[i]=='9'){
				for (int j:l[i]){
					swap(w[i],w[j]);
					if (dp[m[w]]>d+1){
						dp[m[w]]=d+1;
						q.push({m[w],d+1});
					}
					swap(w[i],w[j]);
				}
				break;
			}
		}
	}
	cout << (dp[0]==1e9?-1:dp[0]) << "\n";
}
