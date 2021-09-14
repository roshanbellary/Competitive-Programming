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
	freopen(out.c_str(),"w",stdout);;
	setIO();
}
map<string,int> m;
int main(){
	setIO();
	int N; cin >> N;
	set<string> s;
	for (int i=0;i<N;i++){
		string w; cin >> w;
		m[w]++;
		s.insert(w);
	}
	int max = 0;
	string win = "";
	for (string w:s){
		if (m[w]>max){
			win=w;
			max=m[w];
		}
	}
	cout << win << "\n";
}