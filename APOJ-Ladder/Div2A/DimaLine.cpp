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
int N;
int main(){
	setIO();
	cin >> N; int a[N];
	for (int i=0;i<N;i++){
		cin >> a[i];
	}
	vector<pair<int,int>> v;
	bool w = false;
	for (int i=1;i<N;i++){
		int maxi = max(a[i],a[i-1]);
		int mini = min(a[i],a[i-1]);
		for (int j=0;j<v.size();j++){
			if ((mini>v[j].first)&&(maxi>v[j].second)&&(mini<v[j].second)){
				w=true;
			}
			if ((v[j].first>mini)&&(v[j].first<maxi)&&(v[j].second>maxi)){
				w=true;
			}
		}
		v.pb({mini,maxi});
	}
	cout << (w?"yes\n":"no\n");
}
