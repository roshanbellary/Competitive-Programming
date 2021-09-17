/*
USACO 2018 US Open Contest, Platinum
Problem 3. Disruption
http://www.usaco.org/index.php?page=viewproblem2&cpid=842
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
int N,M;
vector<vector<int>> l;
vector<pair<int,int>> paths;
vector<set<pair<int,pair<int,int>>>> npath;
map<pair<int,int>,int> m;
void dfs(int i, int p){
	int big = i;
	for (int j:l[i]){
		if (j!=p){
			dfs(j,i);
			if (npath[j].size()>npath[big].size()){
				big=j;
			}
		}
	}
	swap(npath[i],npath[big]);
	for (int j:l[i]){
		if (j!=p){
			for (pair<int,pair<int,int>> np:npath[j]){
				if (npath[i].find(np)!=npath[i].end()){
					npath[i].erase(np);
				}else{
					npath[i].insert(np);
				}
			}
		}
	}
	if (npath[i].size()>0){
		pair<int,pair<int,int>> e = *npath[i].begin();
		m[make_pair(i,p)]=e.first;
		m[make_pair(p,i)]=e.first;
	}else{
		m[make_pair(i,p)]=-1;
		m[make_pair(p,i)]=-1;
	}
}
int main(){
	setIO("disrupt");
	cin >> N >> M;
	for (int i=0;i<N;i++) l.push_back(vector<int>()),npath.push_back(set<pair<int,pair<int,int>>>());
	for (int i=0;i<N-1;i++){
		int p, q; cin >> p >> q; p--; q--;
		l[p].push_back(q);
		l[q].push_back(p);
		paths.push_back(make_pair(p,q));
	}
	for (int i=0;i<M;i++){
		int s,f,d;
		cin >> s >> f >> d;
		s--;f--;
		npath[s].insert(make_pair(d,make_pair(s,f)));
		npath[f].insert(make_pair(d,make_pair(s,f)));
	}
	dfs(0,0);
	for (pair<int,int> a:paths){
		cout << m[a] << "\n";
	}
}
