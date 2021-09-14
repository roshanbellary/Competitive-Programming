#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int N, B; cin >> N >> B;
	vector<pair<int,int>> s;
	for (int i=0;i<N;i++){//sorts the islands according to depth
		int size; cin >> size;
		s.push_back(make_pair(size,i));
	}
	sort(s.begin(),s.end());
	vector<pair<pair<int,int>,int>> t;
	for (int i=0;i<B;i++){//sorts the given shoes
		int a, b; cin >> a >> b; // a is the snow depth and b is the distance
		t.push_back(make_pair(make_pair(a,b),i));
	}
	sort(t.begin(),t.end());
	vector<bool> results(B);
	set<int> active;
	set<pair<int,pair<int,int>>> distances;
	for (int i=0;i<N;i++){
		active.insert(i);
	}
	for (int i=0;i<N-1;i++){
		distances.insert(make_pair(1,make_pair(i,i+1)));
	}
	int j = N-1;
	for (int i=B-1;i>=0;i--){
		while (j>=0){
			if (s[j].first<=t[i].first.first){
				break;
			}else{//erasing island and updating distances
				auto itr = active.upper_bound(s[j].second);
				if (itr==active.end()){
					itr--;
					if (itr==active.begin()){
						distances.clear();
						distances.insert(make_pair(0,make_pair(*itr,*itr)));
						break;
					}else{
						int ind = *itr;
						itr--;
						distances.erase(make_pair(ind-*itr,make_pair(*itr,ind)));
					}
				}else{
					int ai = *itr;
					itr--;
					if (itr==active.begin()){
						distances.erase(make_pair(ai-*itr,make_pair(*itr,ai)));
					}else{
						int ind = *itr;
						itr--;
						int bi = *itr;
						distances.erase(make_pair(ind-bi,make_pair(bi,ind)));
						distances.erase(make_pair(ai-ind,make_pair(ind,ai)));
						distances.insert(make_pair(ai-bi,make_pair(bi,ai)));
					}
				}
			}
			active.erase(s[j].second);
			j--;
		}
		results[t[i].second]=((distances.rbegin()->first)<=(t[i].first.second));
	}
	for (int i=0;i<results.size();i++){
		cout << results[i] << "\n";
	}
}
