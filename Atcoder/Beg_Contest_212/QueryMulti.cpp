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
ll col = 0;
class Multi{
	public:
		multiset<ll> m;
		ll add=0;
		bool change=false;
		bool operator< (const Multi &n) const{
			return (*m.begin()-add<*n.m.begin()-n.add);
		}
};
int Q;
vector<pair<int,int>> op;
int main(){
	setIO();
	cin >> Q;
	for (int i=0;i<Q;i++){
		int p; cin >> p;
		int x = 3;
		if (p!=3){
			cin >> x;
		}
		op.push_back(make_pair(p,x));
	}
	set<Multi> st;
	vector<Multi> ns;
	for (int i=0;i<Q;i++){
		if (op[i].first==1){
			if (ns.size()==0){
				Multi n;
				n.m.insert(op[i].second);
				n.add=col;
				ns.push_back(n);
			}else if (ns[ns.size()-1].change){
				Multi n;
				n.m.insert(op[i].second);
				n.add=col;
				ns.push_back(n);
			}else{
				ns[ns.size()-1].m.insert(op[i].second);
			}
		}
		if (op[i].first==2){
			col+=op[i].second;
		}
		if (op[i].first==3){
			for (int j=0;j<ns.size();j++){
				st.insert(ns[j]);
			}
			ns.clear();
			Multi n = *(st.begin());
			cout << *n.m.begin()+col-n.add<< "\n";
			st.erase(st.begin());
			n.m.erase(n.m.begin());
			if (n.m.size()>0){
				st.insert(n);
			}
		}
	}
}
