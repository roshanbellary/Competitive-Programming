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
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N;
pair<int,int> v[(int)(2e5+1)];
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++){cin >> v[i].first;v[i].second=i;}
	sort(v,v+N,greater<pair<int,int>>());
	cout << v[1].second+1 << "\n";
}
