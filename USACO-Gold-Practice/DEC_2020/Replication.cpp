/*
Problem: 
Problem Link: 
Notes: 
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
#define f first
#define s second
int mod=1e9+7;
inline void rv(int &n){
    n=0;int m=1;char c=getchar();if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar();if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){double p = 0.1;c=getchar();for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}}
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){double p = 0.1;c=getchar();for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}}
    n*=m;
}
inline void rv(string &w){w="";char c=getchar();while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar();}}
inline void rv(char &c){c=getchar();}
template<typename T, typename ...Types>
inline void rv(T &n, Types&&... args){rv(n);rv(args...);}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
int main(){
	int n;
	ll d;
	cin >> n >> d;
	bool empty[n][n];
	vector<pair<int, int> > starts;
	vector<pair<int, int> > rocks;
	int dist_rock[n][n];
	int dist_source[n][n];
	bool ans[n][n];
	for(int i = 0; i<n; i++){
		string s;
		cin >> s;
		for(int j = 0; j<n; j++){
			if(s[j]=='#'){
				empty[i][j] = false;
				rocks.push_back(make_pair(i,j));
			}
			else{
				empty[i][j] = true;
			}
			if(s[j]=='S'){
				starts.push_back(make_pair(i,j));
			}
			dist_rock[i][j] = -1;
			dist_source[i][j] = -1;
			ans[i][j] = false;
		}
	}
	vector<pair<int, int> > bfs_list;
	for(int i = 0; i<rocks.size(); i++){
		bfs_list.push_back(rocks[i]);
		dist_rock[rocks[i].first][rocks[i].second] = 0;
	}
	for(int i = 0; i<bfs_list.size(); i++){
		pair<int, int> now = bfs_list[i];
		for(int j = 0; j<4; j++){
			pair<int, int> to = make_pair(now.first+dr[j],now.second+dc[j]);
			if(!(to.first>=0 && to.first<n && to.second>=0 && to.second<n)){
				continue;
			} 
			if(dist_rock[to.first][to.second]!=-1){
				continue;
			}
			int to_dist = dist_rock[now.first][now.second] + 1;
			dist_rock[to.first][to.second] = to_dist;
			bfs_list.push_back(to);
		}
	}
	bfs_list.clear();
	for(int i = 0; i<starts.size(); i++){
		bfs_list.push_back(starts[i]);
		dist_source[starts[i].first][starts[i].second] = 0;
	}
	vector<pair<int, int> > centers[n*n];
	for(int i = 0; i<bfs_list.size(); i++){
		pair<int, int> now = bfs_list[i];
		ans[now.first][now.second] = true;
		int now_dist = dist_source[now.first][now.second];
		centers[dist_rock[now.first][now.second]-1].push_back(now);
		// Do not continue if replicating would force robots to rocks
		if(now_dist>=d*dist_rock[now.first][now.second]){
			continue;
		}
		for(int j = 0; j<4; j++){
			pair<int, int> to = make_pair(now.first+dr[j],now.second+dc[j]);

			if(!(to.first>=0 && to.first<n && to.second>=0 && to.second<n)){
				continue;
			} 
			if(dist_source[to.first][to.second]!=-1){
				continue;
			}
			if(!empty[to.first][to.second]){
				continue;
			}
			int to_dist = now_dist + 1;
			if(to_dist > d*dist_rock[to.first][to.second]){
				continue;
			}
			dist_source[to.first][to.second] = to_dist;
			bfs_list.push_back(to);
		}
	}
	vector<pair<int, int> > next_stage;
	for(int i = n*n-1; i>=0; i--){
		swap(bfs_list,next_stage);
		next_stage.clear();
		for(int j = 0; j<bfs_list.size(); j++){
			pair<int, int> now = bfs_list[j];
			for(int k = 0; k<4; k++){
				pair<int, int> to = make_pair(now.first+dr[k],now.second+dc[k]);

				if(!(to.first>=0 && to.first<n && to.second>=0 && to.second<n)){
					continue;
				} 
				if(ans[to.first][to.second]){
					continue;
				}
				if(!empty[to.first][to.second]){
					continue;
				}
				ans[to.first][to.second] = true;
				next_stage.push_back(to);
			}
		}
		for(int j = 0; j<centers[i].size(); j++){
			next_stage.push_back(centers[i][j]);
		}
	}
	int tot = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(ans[i][j]){
				tot++;
			}
		}
	}
	cout << tot << endl;
}