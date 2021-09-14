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
double Y, K, N;
int main(){
	setIO();
	cin >> Y >> K >> N;
	ll start = ceil(Y/K);
	ll end = floor(N/K);
	int counts = 0;
	if (start<=end){
		for (int i=start;i<=end;i++){
			if (K*i-Y==0) continue;
			counts++;
			cout << (ll)(K*i-Y) << " ";
		}
		cout << "\n";
	}
	if (counts==0) cout << "-1\n";
}
