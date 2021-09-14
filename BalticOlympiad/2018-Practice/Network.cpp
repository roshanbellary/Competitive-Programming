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
int N;
vector<vector<int>> l(5e5,vector<int>());
vector<vector<int>> z(5e5,vector<int>());
vector<pair<int,int>> pairs;
void dfs(int i, int p){
	if (i==0){
		for (int j:l[i]){
			if (j!=p){
				dfs(j,i);
			}
		}
		vector<vector<int>> col;
		if (l[0].size()==1) col.pb(vector<int>(1,0));
		for (int j:l[i]){
			if (j!=p){
				col.pb(z[j]);
			}
		}
		for (int j=0;j<col.size()-1;j+=2){
			pairs.pb({col[j][0],col[j+1][0]});
		}
		if (col.size()%2==1){
			bool w = false;
			for (int i=0;i<col.size()-1;i++){
				if (col[i].size()>1){
					pairs.pb({col[col.size()-1][0],col[i][1]});
					w=true;
					for (int j=0;j<col.size();j++){
						col[i].erase(col[i].begin());
					}
					col[i].erase(col[i].begin());
					break;
				}
			}
			if (!w){
				pairs.pb({col[col.size()-1][0],0});
				for (int i=0;i<col.size();i++){
					col[i].erase(col[i].begin());
				}
			}
		}else{
			for (int i=0;i<col.size();i++){
				col[i].erase(col[i].begin());
			}
		}
		vector<int> make;
		for (int i=0;i<col.size();i++){
			for (int j=0;j<col[i].size();j++){
				make.pb(col[i][j]);
			}
		}
		for (int i=0;i<make.size()-1;i+=2){
			pairs.pb({make[i],make[i+1]});
		}
		if (make.size()%2==1){
			pairs.pb({make[make.size()-1],0});
		}
	}else{
		int max = 0; int pos = -1;
		for (int j:l[i]){
			if (j!=p){
				dfs(j,i);
				if (z[j].size()>max){pos=j;max=z[j].size();}
			}
		}
		if (pos!=-1){
			swap(z[pos],z[i]);
			for (int j:l[i]){
				if (j!=p){
					for (int k:z[j]){
						z[i].pb(k);
					}
				}
			}
		}
		if (l[i].size()==1){z[i].pb(i);}
	}
}
int main(){
	setIO("Network");
	cin >> N;
	for (int i=0;i<N-1;i++){
		int a, b; cin >> a >> b;
		l[--a].pb(--b);
		l[b].pb(a);
	}
	dfs(0,0);
	cout << pairs.size() << "\n";
	for (pair<int,int> a:pairs){
		cout << a.first+1 << " " << a.second+1 << "\n";
	}
}
