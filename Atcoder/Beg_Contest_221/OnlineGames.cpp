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
int N; int c[(int)2e5+1];
class Range{
	public:	
		int s,f;
		bool t;
};
vector<Range> r;
bool sorts(Range &a, Range &b){
	if (a.s==b.s){
		if (!a.t){
			return true;
		}else if (!b.t){
			return false;
		}
	}
	return (a.s<=b.s);
}
int main(){
	setIO();cin >> N;
	for (int i=0;i<N;i++){
		int s, f; cin >> s >> f;f+=s;
		Range st; st.s=s;st.f=f; st.t=true;
		Range fi; fi.s=f;fi.f=s; fi.t=false;
		r.pb(st); r.pb(fi);
	}
	sort(r.begin(),r.end(),sorts);
	multiset<pair<int,int>> m;
	for (int i=0;i<r.size();i++){
		if (r[i].t){
			m.insert({r[i].f,r[i].s});
		}else{
			auto itr = m.upper_bound({r[i].s,0}); auto itr2=itr;
			vector<int> val;
			while (itr!=m.end()){
				if (itr->first==r[i].s){
					int diff = (r[i].s-itr->second);
					val.pb(diff);
				}else{
					break;
				}
				itr++;
			}
			if (itr2!=itr) m.erase(itr2,itr);
			sort(val.begin(),val.end(),greater<int>());
			int col = 0;
			for (int z=0;z<val.size();z++){
				int j=z+1;
				while (j<val.size()){
					if (val[j]==val[z]){j++;}
					else{
						break;
					}
				}
				if (j<val.size()){
					c[m.size()-col]+=(val[z]-val[j]);
					col+=(j-z);
				}else{
					c[m.size()-col]+=(val[z]);
				}
				z=j-1;
			}
		}
	}
	for (int i=0;i<N;i++){
		cout << c[i] << " ";
	}
	cout << "\n";
}
