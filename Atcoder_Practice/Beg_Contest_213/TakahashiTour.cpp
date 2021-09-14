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
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N;
vector<set<int>> l;
vector<bool> v;
vector<int> cities;
bool dfs(int i){
	cities.push_back(i);
	v[i]=true;
	bool c = true;
	for (int j:l[i]){
		if (!v[j]){
			if (dfs(j)){
				c=true;
			}else{
				c=false;
			}
			cities.push_back(i);
		}
	}
	return c;
}
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++){l.push_back(set<int>()); v.push_back(false);}
	for (int i=0;i<N-1;i++){
		int a,b; cin >> a >> b;
		a--;b--;
		l[a].insert(b);
		l[b].insert(a);
	} 
	dfs(0);
	for (int j:cities){
		cout << j+1 << " ";
	}
	cout << "\n";
}
