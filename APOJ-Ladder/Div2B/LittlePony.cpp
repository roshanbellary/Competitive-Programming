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
int v[(int)(1e5+1)];
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++) cin >> v[i];
	int loc = -1;
	int change = 0;
	for (int i=0;i<N-1;i++){
		if (v[i]>v[i+1]) {change++;loc=i;break;}
	}
	if (change==0){
		cout << "0\n";
	}else{
		rotate(v,v+loc+1,v+N);
		bool w = true;
		for (int i=0;i<N-1;i++){
			if (v[i]>v[i+1]){w=false;break;}
		}
		if (w) cout << (N-loc-1) << "\n";
		else cout << "-1\n";
	}
}
