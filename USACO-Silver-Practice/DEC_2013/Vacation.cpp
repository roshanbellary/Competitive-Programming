#include <bits/stdc++.h>
#define int long long
using namespace std;
int N, M, K, Q;
vector<vector<pair<int,int>>> l;
vector<vector<int>> d;
int32_t main(){
	freopen("vacation.in","r",stdin);
	freopen("vacation.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> N >> M >> K >> Q;
	for (int i=0;i<N;i++){
		l.push_back(vector<pair<int,int>>());
		d.push_back(vector<int>(N,-1));
	}
	for (int i=0;i<M;i++){
		int u,v,d;
		cin >> u >> v >> d;
		u--; v--;
		l[u].push_back(make_pair(v,d));
	}
	for (int i=0;i<N;i++){
		priority_queue<pair<int,int>> pq;
		pq.push(make_pair(0,i));
		while (!pq.empty()){
			int j = pq.top().second;
			int dist = -pq.top().first;
			pq.pop();
			if ((d[i][j]>=0)) continue;
			d[i][j]=dist;
			for (pair<int,int> a:l[j]){
				if (d[i][a.first]<0){
					pq.push(make_pair(-(dist+a.second),a.first));
				}
			}
		}
	}
	int works = 0;
	long long mindist = 0;
	for (int i=0;i<Q;i++){
		int a,b;
		cin >> a >> b; a--; b--;
		long long distmin = 1e18;
		bool w = false;
		for (int j=0;j<K;j++){
			if ((d[a][j]<0)||(d[j][b]<0)) continue;
			w=true;
			long long dist = d[a][j]+d[j][b];
			distmin=min(distmin,dist);
		}
		if (w){works++; mindist+=distmin;}
	}
	cout << works << "\n" << mindist << "\n";
}
