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
int N, M;
int g[51][51];
int main(){
	setIO();
	cin >> N >> M;
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			cin >> g[i][j];
		}
	}
	vector<pair<int,int>> good;
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			if (g[i][j]==1) good.pb({i,j});
		}
	}
	bool two = false;
	int sides = 0;
	for (int i=0;i<good.size();i++){
		if ((good[i].first==0)||(good[i].first==N-1)||(good[i].second==0)||(good[i].second==M-1)){sides++;}
	}
	if (sides>=1){
		cout << "2\n";
	}else{
		cout << "4\n";
	}
}
