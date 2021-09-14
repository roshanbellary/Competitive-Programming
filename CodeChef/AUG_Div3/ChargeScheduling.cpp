#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
#define int long long
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
int Q, N;
int v[300001];
int t[300001];
int32_t main(){
	setIO();
	cin >> Q;
	for (int l=0;l<Q;l++){
		cin >> N;
		priority_queue<pair<pair<int,int>,int>> pq;
		for (int i=0;i<N;i++) cin >> v[i];
		for (int i=0;i<N;i++) cin >> t[i];
		for (int i=0;i<N;i++){pq.push(make_pair(make_pair(-(t[i]-v[i]),-t[i]),i));}
		vector<int> ops;
		int T = 0;
		while (!pq.empty()){
			int time = -pq.top().first.first;
			int dline = -pq.top().first.second;
			int ind = pq.top().second;
			pq.pop();
			if (time<T) continue;
			T++; ops.push_back(ind+1);
			time++;
			if (time!=dline){
				pq.push({{-time,-dline},ind});
			}
		}
		int count = 0;
		int i = 0;
		while ((count<2*N)&&(i<ops.size())){
			int j = i+1;
			while (j<ops.size()){
				if (ops[j]==ops[i]) j++;
				else{break;}
			}
			cout << ops[i]+1 << " " << i << " " << j << "\n";
			i=j;
			count++;
		}
	}
}
