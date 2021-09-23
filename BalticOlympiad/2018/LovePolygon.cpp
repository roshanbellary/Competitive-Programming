/*
Baltic Olympiad in Informatics 2018 Open - day 1 Problem A Love Polygon
https://boi18-day1-open.kattis.com/problems/lovepolygon
I had to look at the editorial to see how to handle the case where you have a cycle along with 
acyclic trees connecting to the cycle. This problem was really hard for me to understand
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
int matching(vector<bool> necklace){
	int len = (int) necklace.size();
	bool allzero = true;
	for (int i=0;i<len;i++) if(necklace[i]) allzero = false;
	if(allzero) return len / 2;
	int ans = 0;
	for (int i=0;i<len;i++){
		int i1 = (i+1) % len;
		if(necklace[i] && !necklace[i1]){
			int curlen = 0;
			while(!necklace[i1]){
				++curlen;
				i1 = (i1 + 1) % len;
			}
			ans += curlen / 2;
		}
	}
	return ans;
}

int main() {
	setIO();
	int n;
	cin >> n;
	if(n % 2 == 1){
		cout << -1 << endl;
		return 0;
	}
	map<string,int> rename;
	int curix = 0;
	vector<int> parent(n);
	for (int i=0;i<n;i++){
		string s, t;
		cin >> s >> t;
		
		if(!rename.count(s)) rename[s] = curix++;
		if(!rename.count(t)) rename[t] = curix++;

		parent[ rename[s] ] = rename[t];
	}
	vector<vector<int>> children(n);
	for (int i=0;i<n;i++) children[parent[i]].push_back(i);
	int totmatch = 0;
	vector<bool> vis(n, false);
	vector<int> maxmatch(n, 0);
	vector<bool> aminmatch(n, false);
	vector<bool> oncycle(n, false);

	function<void(int)> calc = [&](int v){ 
		for (int u:children[v]) if(!oncycle[u]){
			calc(u);
			maxmatch[v] += maxmatch[u];

			if( !aminmatch[u] ) aminmatch[v] = true;
		}

		if( aminmatch[v] ) maxmatch[v]++;
	};

	for (int i=0;i<n;i++) if(!vis[i]){
		int sizeofcomp = 0;
		stack<int> st;
		st.push(i);
		vis[i] = true;
		while(!st.empty()){
			int j = st.top();
			st.pop();
			
			++sizeofcomp;

			if(!vis[ parent[j] ]){
				vis[parent[j]] = true;
				st.push(parent[j]);
			}
			for (int k:children[j]) if(!vis[k]){
				vis[k] = true;
				st.push(k);
			}
		}
		int j = i;
		for (int j=0;j<sizeofcomp;j++) j = parent[j];
		vector<int> cycle;
		int j1 = j;
		do {
			oncycle[j1] = true;
			cycle.push_back(j1);
			j1 = parent[j1];
		} while(j1 != j);
		int curmatch = 0;
		vector<bool> necklace;
		for (int v:cycle){
			calc(v);
			curmatch += maxmatch[v];
			necklace.push_back( aminmatch[v] );
		}

		if(cycle.size() == 2){
			curmatch -= necklace[0] + necklace[1];
			curmatch += 2;
		} else {
			curmatch += matching(necklace);
		}
		totmatch += curmatch;
	}
	cout << n - totmatch << endl;
}
