#include <bits/stdc++.h>
using namespace std;
int N, M;
const int dps = 5*1e5+1;
bool dpb[100][dps];
bool dpe[100][dps];
vector<vector<pair<int,pair<int,int>>>> l;
vector<set<int>> b;
vector<set<int>> e;
int main(){
	freopen("meeting.in","r",stdin);
	freopen("meeting.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> N >> M;
	b.resize(N,set<int>());
	e.resize(N,set<int>());
	int maxb = 0;
	int maxe = 0;
	for (int i=0;i<N;i++)
		l.push_back(vector<pair<int,pair<int,int>>>());
	for (int i=0;i<M;i++){
		int j,k,b,e;
		cin >> j >> k >> b >> e;
		maxb+=b;
		maxe+=e;
		j--; k--;
		l[j].push_back(make_pair(k,make_pair(b,e)));
	}
	queue<pair<int,int>> q1;
	q1.push(make_pair(0,0));
	dpb[0][0]=true;
	while (!q1.empty()){
		int i = q1.front().first;
		int dist = q1.front().second;
		q1.pop();
		for (pair<int,pair<int,int>> a:l[i]){
			if (!dpb[a.first][a.second.first+dist]){
				dpb[a.first][a.second.first+dist]=true;
				q1.push(make_pair(a.first,a.second.first+dist));
			}
		}
	}
	queue<pair<int,int>> q2;
	dpe[0][0]=true;
	q2.push(make_pair(0,0));
	while (!q2.empty()){
		int i = q2.front().first;
		int dist = q2.front().second;
		q2.pop();
		for (pair<int,pair<int,int>> a:l[i]){
			if (!dpe[a.first][a.second.second+dist]){
				dpe[a.first][a.second.second+dist]=true;
				q2.push(make_pair(a.first,a.second.second+dist));
			}
		}
	}
	int mindist = -1;
	for (int i=0;i<5*1e5+1;i++){
		if (dpb[N-1][i]&&dpe[N-1][i]){
			mindist=i;
			break;
		}
	}
	if (mindist>=0) cout << mindist << "\n";
	else cout << "IMPOSSIBLE\n";
}
