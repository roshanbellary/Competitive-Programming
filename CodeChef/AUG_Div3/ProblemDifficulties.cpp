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
int T;
int main(){
	setIO();
	cin >> T;
	for (int l=0;l<T;l++){
		set<int> v;
		int a[4];
		for (int i=0;i<4;i++){int n; cin >> n; v.insert(n); a[i]=n;}
		if (v.size()==1) cout << "0\n";
		else if (v.size()==2){
			int counts = 0;
			for (int i=0;i<4;i++){
				if (a[i]==*v.begin()){
					counts++;
				}
			}
			if (counts==2) cout << "2\n";
			else cout << "1\n";
		}else cout << "2\n";
		
	}
}
