#include <bits/stdc++.h>
using namespace std;
vector<bool> c(1e6,false);
int main(){
	freopen("invite.in","r",stdin);
	freopen("invite.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int N, G; cin >> N >> G;
	int totcount=0;
	vector<pair<int,set<int>>> g;
	for (int i=0;i<G;i++){
		int s;cin >> s;
		g.push_back(make_pair(0,set<int>()));
		for (int j=0;j<s;j++){
			int v; cin >> v; v--;
			g[g.size()-1].second.insert(v);
		}
	}
	queue<int> q;
	q.push(0);
	while (!q.empty()){
		int num = q.front(); q.pop();
		if (c[num]) continue;
		c[num]=true;
		for (int i=0;i<G;i++){
			if (g[i].second.find(num)!=g[i].second.end()){
				g[i].first++;
				if (g[i].first==g[i].second.size()-1){
					for (int j:g[i].second){
						if (!c[j]){ q.push(j); break;}
					}
				}
			}
		}
	}
	int count = 0;
	for (int i=0;i<N;i++){
		if (c[i]) count++;
	}
	cout << count << "\n";
}
