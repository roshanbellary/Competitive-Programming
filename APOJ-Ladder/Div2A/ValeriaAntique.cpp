#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int N, V; cin >> N >> V;
	vector<int> s;
	for (int i=0;i<N;i++){
		int K; cin >> K;
		bool w = false;
		for (int j=0;j<K;j++){
			int store; cin >> store;
			if (store<V){
				w=true;
			}
		}
		if (w) s.push_back(i+1);
	}
	cout << s.size() << "\n";
	for (int j:s) cout << j << " ";
	cout << "\n";
}
