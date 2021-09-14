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
		int N; cin >> N;int v[N];
		for (int i=0;i<N;i++) cin >> v[i];
		int mini = 1e9;
		for (int i=0;i<N;i++){
			if (v[i]<mini) mini=v[i];
		}
		int len = log2(mini)+1;
		int res = 0;
		for (int i=0;i<len;i++){
			bool w=true;
			for (int j=0;j<N;j++){
				if (v[j]&(1<<i)){
					continue;
				}else{
					w=false;break;
				}
			}
			if (w) res+=(1<<i);
		}
		cout << res << "\n";

	}
}
