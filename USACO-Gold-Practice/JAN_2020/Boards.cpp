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
ll N, P;
int32_t main(){
	setIO("boards");
	cin >> N >> P;
	vector<pair<pair<int,int>,pair<int,int>>> b;
	vector<ll> travel(P,0);
	for (int i=0;i<P;i++){
		int sx,sy,fx,fy;
		cin >> sx >> sy >> fx >> fy;
		b.push_back(make_pair(make_pair(sx,sy),make_pair(1,i)));
		b.push_back(make_pair(make_pair(fx,fy),make_pair(0,i)));
		travel[i]=fx+fy;
	}
	sort(b.begin(),b.end());
	vector<ll> dp(P,0);
	map<ll,ll> m;
	for (int i=0;i<b.size();i++){
		if (b[i].second.first==1){
			auto itr = m.upper_bound(b[i].first.second);
			ll exp = 0;
			if (itr!=m.begin()) itr=prev(itr), exp=itr->second;
			dp[b[i].second.second]=exp+b[i].first.first+b[i].first.second;
		}else{
			if (m.size()>0){
				ll res=dp[b[i].second.second]-b[i].first.first-b[i].first.second;
				auto itr = m.upper_bound(b[i].first.second);
				ll exp = 0;
				if (itr!=m.begin()){
					itr=prev(itr);
					exp=itr->second;
					if (exp>res){
						itr++;
						while (itr!=m.end()){
							if (itr->second>res){m.erase(itr++);continue;}
							itr++;
						}
						m[b[i].first.second]=res;
					}
				}else{
					while (itr!=m.end()){
						if (itr->second>res){m.erase(itr++);continue;}
						itr++;
					}
					m[b[i].first.second]=res;
				}
			}else{
				ll res=dp[b[i].second.second]-b[i].first.first-b[i].first.second;
				m[b[i].first.second]=res;
			}
		}
	}
	cout << m.rbegin()->second+2*N << "\n";
}
