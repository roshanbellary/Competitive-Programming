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
int N;
int main(){
	setIO();
	cin >> N;
	vector<pair<int,int>> e;
	for (int i=0;i<N;i++){
		int a,b; cin >> a >> b;
		e.push_back(make_pair(a,b));
	}
	sort(e.begin(),e.end());
	int maxi = 0;
	for (int i=0;i<N;i++){
		if (maxi>e[i].second){
			maxi=e[i].first;
		}else maxi=e[i].second;
	}
	cout << maxi << "\n";
}
