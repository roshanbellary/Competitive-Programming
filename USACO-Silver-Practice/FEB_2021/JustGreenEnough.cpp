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
#define mod 1e9+7
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
pair<int,int> s[500][500];
pair<int,int> s2[500][500];
int g[500][500];
int N;
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			cin >> g[i][j];
		}
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (i){
				if (g[i][j]<100) s[i][j].first=0;
				else s[i][j].first=s[i-1][j].first+1;
			}else{
				if (g[i][j]<100) s[i][j].first=0;
				else s[i][j].first=1;
			}
			if (j){
				if (g[i][j]<100) s[i][j].second=0;
				else s[i][j].second=s[i][j-1].second+1;
			}else{
				if (g[i][j]<100) s[i][j].second=0;
				else s[i][j].second=1;
			}
		}
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (i){
				if (g[i][j]<101) s2[i][j].first=0;
				else s2[i][j].first=s2[i-1][j].first+1;
			}else{
				if (g[i][j]<101) s2[i][j].first=0;
				else s2[i][j].first=1;
			}
			if (j){
				if (g[i][j]<101) s2[i][j].second=0;
				else s2[i][j].second=s2[i][j-1].second+1;
			}else{
				if (g[i][j]<101) s2[i][j].second=0;
				else s2[i][j].second=1;
			}
		}
	}
	ll rect100 = 0;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			int mini = 1e9;
			for (int z=j;z>j-s[i][j].second;z--){
				mini=min(mini,s[i][z].first);
				rect100+=mini;
			}
		}
	}
	ll rect101 = 0;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			int mini = 1e9;
			for (int z=j;z>j-s2[i][j].second;z--){
				mini=min(mini,s2[i][z].first);
				rect101+=mini;
			}
		}
	}
	cout << rect100-rect101 << "\n";
}
