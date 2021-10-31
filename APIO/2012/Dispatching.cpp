/*
Problem: APIO '12 P1 - Dispatching
Problem Link: https://dmoj.ca/problem/apio12p1
Notes:  I had done this Problem before, re-solved it.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
}
void setIO(string f){
	string in = f+".in";
	string out = f+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	setIO();
}
int N, M;
vector<vector<int>> adj;
vector<multiset<ll>> s;
vector<ll> lead;
vector<ll> sum;
ll totmax = 0;
void dfs(int i, int p){
	int big = i;
	for (int j:adj[i]){
		if (j!=p){
			dfs(j,i);
			if (s[j].size()>s[big].size()){
				big=j;
			}
		}
	}
	swap(s[i],s[big]);
	swap(sum[i],sum[big]);
	for (int j:adj[i]){
		if (j!=p){
			for (ll k:s[j]){
				if (k+sum[i]<=M){
					s[i].insert(k);
					sum[i]+=k;
				}else if (k<(*s[i].rbegin())){
					auto itr = s[i].end(); itr--;
					sum[i]-=(*itr);
					s[i].erase(itr);
					s[i].insert(k);
					sum[i]+=k;
				}
			}
		}
	}
	if ((s[i].size()*lead[i])>totmax) totmax = (s[i].size()*lead[i]);
}
int main(){
	setIO();
	cin >> N >> M;
	for (int i=0;i<N;i++){adj.push_back(vector<int>()),s.push_back(multiset<ll>());};
	for (int i=0;i<N;i++){
		ll b,c,l;
		cin >> b >> c >> l;
		b--;
		lead.push_back(l);
		if (b>=0) adj[b].push_back(i);
		s[i].insert(c);
		sum.push_back(c);
	}
	dfs(0,0);
	cout << totmax << "\n";
}
