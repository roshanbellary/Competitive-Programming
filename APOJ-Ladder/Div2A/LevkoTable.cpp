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
int N,K;
int main(){
	setIO();
	cin >> N >> K;
	int v[N][N];
	memset(v,0,sizeof(v));
	for (int i=0;i<N;i++){
		v[i][i]=K;
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}
