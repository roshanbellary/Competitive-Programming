#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> g;
bool checkpos(int i, int j){
	int count = 0;
	if (i>0) count+=g[i-1][j];
	if (j>0) count+=g[i][j-1];
	if (i<N-1) count+=g[i+1][j];
	if (j<N-1) count+=g[i][j+1];
	return (count%2==0);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> N;
	for (int i=0;i<N;i++){
		g.push_back(vector<int>(N,0));
	}
	for (int i=0;i<N;i++){
		string w; cin >> w;
		for (int j=0;j<N;j++){
			if (w[j]=='o'){
				g[i][j]=1;
			}
		}
	}
	bool w = true;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (!checkpos(i,j)){w=false;break;}
		}
		if (!w) break;
	}
	if (w) cout << "YES\n";
	else cout << "NO\n";
}
