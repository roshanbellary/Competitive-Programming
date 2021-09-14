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
int N, Q;
const int s = 5e3;
int a[s];
ll v[s][s];
ll arr[(int)(2e6+1)];
int main(){
	setIO("threesum");
	cin >> N >> Q;
	for (int i=0;i<N;i++){
		cin >> a[i];
	}
	for (int i=N-1;i>=0;i--){
		for (int j=i+1;j<N;j++){
			if ((-(a[j]+a[i])+1e6>=0)&&(-(a[j]+a[i])+1e6<=2e6)){
				v[i][j]+=arr[(int)(-(a[j]+a[i])+1e6)];
			}
			arr[(int)(a[j]+1e6)]++;
		}
		for (int j=i+1;j<N;j++){
			arr[(int)(a[j]+1e6)]--;
		}
	}
	for (int i=N-1;i>=0;i--){
		for (int j=i+1;j<N;j++){
			v[i][j]+=(v[i+1][j]+v[i][j-1]-v[i+1][j-1]);
		}
	}
	for (int i=0;i<Q;i++){
		int a,b; cin >> a >> b;
		a--;b--;
		cout << v[a][b]<< "\n";
	}
}
