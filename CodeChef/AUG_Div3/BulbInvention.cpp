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
		int N, P, K; cin >> N >> P >> K; N--;
		int to = N%K;
		int ne = P%K;
		if (ne<=to){
			cout << ne*(N/K+1)+P/K+1 << "\n";
		}else{
			cout << (to+1)*(N/K+1)+(ne-to-1)*(N/K)+P/K+1 << "\n";
		}
	}
}
