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
int N, M, D;
vector<int> p1;
vector<int> p2;
vector<int> s1;
vector<int> s2;
int findRoot1(int i){
	if (i==p1[i]){
		return i;
	}else{
		p1[i]=findRoot1(p1[i]);
		return p1[i];
	}
}
int findRoot2(int i){
	if (i==p2[i]){
		return i;
	}else{
		p2[i]=findRoot2(p2[i]);
		return p2[i];
	}
}
void union1(int v1, int v2){
	v1=findRoot1(v1);
	v2=findRoot1(v2);
	if (v1==v2) return;
	if (s1[v2]>s1[v1]) swap(v1,v2);
	s1[v1]+=s1[v2];
	p1[v2]=v1;
}
void union2(int v1, int v2){
	v1=findRoot2(v1);
	v2=findRoot2(v2);
	if (v1==v2) return;
	if (s2[v2]>s2[v1]) swap(v1,v2);
	s2[v1]+=s2[v2];
	p2[v2]=v1;
}
int main(){
	setIO();
	cin >> N >> M >> D;
	for (int i=0;i<N;i++){p1.pb(i);p2.pb(i);s1.pb(1);s2.pb(1);}
	for (int i=0;i<M;i++){
		int u, v; cin >> u >> v; u--; v--;
		union1(u,v);
	}
	for (int i=0;i<D;i++){
		int u, v; cin >> u >> v;u--;v--;
		union2(u,v);
	}
	int counts = 0;
	vector<pair<int,int>> edges;
	for (int i=0;i<N;i++){
		for (int j=i+1;j<N;j++){
			if (((findRoot1(i)!=findRoot1(j)))&&(findRoot2(i)!=findRoot2(j))){
				union1(i,j);
				union2(i,j);
				edges.pb({i+1,j+1});
				counts++;
			}
		}
	}
	cout << counts << "\n";
	for (int i=0;i<edges.size();i++){
		cout << edges[i].first << " " << edges[i].second << "\n";
	}
}
