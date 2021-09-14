#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
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
int N;
ll v[(int)(1e5+1)];
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++) cin >> v[i];
	sort(v,v+N);
	vector<pair<ll,ll>> counts;
	for (int i=N-1;i>=0;i--){
		int j=i-1;
		while (j>=0){
			if (v[j]==v[i]) j--;
			else{ break;}
		}
		counts.push_back(make_pair(v[i],(i-j)*v[i]));
		i=j+1;
	}
	set<pair<ll,ll>> sums;
	for (int i=0;i<counts.size();i++){
		if (sums.size()==0){
			sums.insert(make_pair(-counts[i].second,counts[i].first));
		}else{
			auto itr = sums.begin();
			if (itr->second!=counts[i].first+1){
				sums.insert(make_pair(-(-itr->first+counts[i].second),counts[i].first));
			}else if (sums.size()<2){
				sums.insert(make_pair(-counts[i].second,counts[i].first));
			}else{
				itr++;
				sums.insert(make_pair(-(-itr->first+counts[i].second),counts[i].first));
			}
		}
	}
	cout << -sums.begin()->first << "\n";
}
