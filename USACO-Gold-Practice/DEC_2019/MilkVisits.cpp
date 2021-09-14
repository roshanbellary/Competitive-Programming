//Working sol created after contest
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
const int s = 100001;
int t[s];
vector<vector<int>> l;
vector<vector<int>> a;
vector<set<pair<int,int>>> types;
vector<int> parent;
vector<int> dep;
vector<unordered_set<int>> req;
vector<stack<int>> col;
int timer = 0;
void dfs(int ind, int p, int d){
	parent[ind]=p;
	dep[ind]=d;
	col[t[ind]-1].push(ind);
	for (auto j:req[ind]){
		if (col[j].size()>0){
			types[ind].insert(make_pair(j,col[j].top()));
		}
	}
	for (int j:l[ind]){
		if (j!=p){
			dfs(j,ind,d+1);
		}
	}
	if (col[t[ind]-1].size()>0) col[t[ind]-1].pop();
}
int lca(int c, int b){
	if (dep[c]>dep[b]) swap(c,b);
	int d = dep[b]-dep[c];
	for (int i=0;i<log2(N);i++){
		if (d&(1<<i)){
			b=a[b][i];
		}
	}
	if (c==b) return c;
	for (int i=log2(N)-1;i>=0;i--){
		if (a[c][i]!=a[b][i]){
			c=a[c][i];
			b=a[b][i];
		}
	}
	return parent[c];
}
int main(){
	setIO("milkvisits");
	cin >> N >> M;
	for (int i=0;i<N;i++) cin >> t[i];
	for (int i=0;i<N;i++) l.push_back(vector<int>());
	for (int i=0;i<N;i++){
		col.push_back(stack<int>());
		req.push_back(unordered_set<int>());
		types.push_back(set<pair<int,int>>());
		a.push_back(vector<int>(ceil(log2(N)+1)));
		parent.push_back(i);
		dep.push_back(0);
	}
	for (int i=0;i<N-1;i++){
		int a,b; cin >> a >> b;
		a--;b--;
		l[a].push_back(b);
		l[b].push_back(a);
	}
	vector<pair<pair<int,int>,int>> q;
	for (int i=0;i<M;i++){
		int a,b, t; cin >> a >> b >> t;t--;
		a--;b--;
		req[a].insert(t);
		req[b].insert(t);
		q.push_back(make_pair(make_pair(a,b),t));
	}
	dfs(0,0,0);
	for (int i=0;i<N;i++){
		a[i][0]=parent[i];
	}
	for (int i=0;i<log2(N);i++){
		for (int j=0;j<N;j++){
			a[j][i+1]=a[a[j][i]][i];
		}
	}
	for (int i=0;i<M;i++){
		int c=q[i].first.first;
		int d=q[i].first.second;
		int type = q[i].second;
		int anc = lca(c,d);
		bool w1=false; bool w2=false;
		auto itr1 = types[c].upper_bound(make_pair(type,-1));
		auto itr2 = types[d].upper_bound(make_pair(type,-1));
		int v1;int v2;
		if (types[c].size()>0){
			if (itr1!=types[c].end()){
				if (itr1->first==type){
					w1=true; v1=itr1->second;
				}
			}
		}
		if (types[d].size()>0){
			if (itr2!=types[d].end()){
				if (itr2->first==type){
					w2=true;v2=itr2->second;
				}
			}
		}
		if (w1){
			if ((lca(anc,v1)==v1)&&(v1!=anc)) w1=false;
		}
		if (w2){
			if ((lca(anc,v2)==v2)&&(v2!=anc)) w2=false;
		}
		cout << (w1||w2);
	}
	cout << "\n";
}
