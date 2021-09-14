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
int T;
int main(){
	setIO();
	cin >> T;
	for (int l=0;l<T;l++){
		int N; cin >> N;
		int v[N];
		for (int i=0;i<N;i++) cin >> v[i];
		int ab = 0;
		int negn = 0;
		int onen = 0;
		for (int i=0;i<N;i++){
			if (abs(v[i])>1) ab++;
			if (v[i]==-1) negn++;
			if (v[i]==1) onen++;
		}
		if (ab>1){
			cout << "0\n";
		}else{
			if ((negn>0)&&(ab==1)){
				cout << "0\n";
			}else if ((negn>=2)&&(onen==0)){
				cout << "0\n";
			}else{
				cout << "1\n";
			}
		}
	}
}
