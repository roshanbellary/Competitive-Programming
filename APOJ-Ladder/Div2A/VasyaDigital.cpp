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
int main(){
	setIO();
	int K,D; cin >> K >> D;
	string r;
	if (D!=0){
		r+=to_string(D);
		for (int i=1;i<K;i++){
			r+="0";
		}
		cout << r << "\n";
	}else if ((D==0)&&(K==1)){
		cout << "0\n";
	}else{
		cout << "No solution\n";
	}
}
