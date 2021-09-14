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
int T,N;
const int s = 10;
int v[s];
int counts = 0;
void recurse(int p, int s){
	if (p==N){
		if (s==0) counts++;
	}else{
		recurse(p+1,s+v[p]);
		recurse(p+1,s-v[p]);
		recurse(p+1,s);
	}
}
int main(){
	setIO();
	cin >> T;
	for (int l=0;l<T;l++){
		cin >> N;
		for (int i=0;i<N;i++){
			cin >> v[i];
		}
		counts = 0;
		recurse(0,0);
		if (counts>1) cout << "YES\n";
		else cout << "NO\n";
	}
}
