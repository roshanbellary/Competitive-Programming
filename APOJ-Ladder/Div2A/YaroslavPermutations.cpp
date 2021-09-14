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
int a[1001];
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++) cin >> a[i];
	set<int> n;
	map<int,int> c;
	for (int i=0;i<N;i++){
		n.insert(a[i]);
		c[a[i]]++;
	}
	vector<int> co;
	for (int j:n) co.push_back(c[j]);
	sort(co.begin(),co.end());
	int sum = 0;
	for (int i=0;i<co.size()-1;i++){
		sum+=co[i];
	}
	if (co[co.size()-1]>sum+1) cout << "NO\n";
	else cout << "YES\n";
}
