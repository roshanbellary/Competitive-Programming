/*

USACO 2014 December Contest, Gold Problem 3. Cow Jog
http://www.usaco.org/index.php?page=viewproblem2&cpid=496
Didn't find difficulty with this problem and found answer fairly easily.
*/
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
ll N, T;
vector<pair<ll,ll>> c;
bool check(int l){
	return true;
}
int main(){
	setIO("cowjog");
	cin >> N >> T;
	for (int i=0;i<N;i++){
		ll x, v; cin >> x >> v;
		c.pb({x,v});
	}
	vector<stack<ll>> st;
	for (int i=0;i<N;i++){
		if (st.size()==0){
			st.pb(stack<ll>());
			st[0].push(c[i].first+c[i].second*T);
		}else{
			int s = 0;
			int f = st.size();
			while (s!=f){
				int mid = (s+f)/2;
				if (st[mid].top()>=c[i].first+c[i].second*T){
					s=mid+1;
				}else{
					f=mid;
				}
			}
			if (s==st.size()){
				st.pb(stack<ll>());
				st[st.size()-1].push(c[i].first+c[i].second*T);
			}else{
				st[s].push(c[i].first+c[i].second*T);
			}
		}
	}
	cout << st.size() << "\n";
}
