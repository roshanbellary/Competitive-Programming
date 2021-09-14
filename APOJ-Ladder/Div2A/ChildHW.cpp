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
	int l[4];
	char c[4]={'A','B','C','D'};
	for (int i=0;i<4;i++){
		string s; cin >> s;
		l[i]=s.length()-2;
	}
	vector<int> pos;
	for (int i=0;i<4;i++){
		bool ts = true;
		bool tl = true;
		for (int j=0;j<4;j++){
			if (i==j) continue;
			else{
				if ((l[i]*2>l[j])) ts=false;
				if (l[i]<l[j]*2) tl=false;
			}
		}
		if (ts||tl){
			pos.push_back(i);
		}
	}
	if (pos.size()==1){
		cout << c[pos[0]] << "\n";
	}else{
		cout << c[2] << "\n";
	}
}
