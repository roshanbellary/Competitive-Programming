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
int N, M;
vector<int> a;
vector<int> b;
int main(){
	setIO();
	cin >> N >> M;
	for (int i=0;i<N;i++){
		int v; cin >> v;
		a.push_back(v);
	}
	for (int i=0;i<M;i++){
		int v; cin >> v;
		b.push_back(v);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int minD = 1e9;
	int j = 0;
	for (int i=0;i<N;i++){
		while ((j<M)){
			if (b[j]>=a[i]){
				break;
			}else{
				j++;
			}
		}
		if (j!=M){
			minD = min(minD,abs(b[j]-a[i]));
		}
	}
	j = M-1;
	for (int i=N-1;i>=0;i--){
		while (j>=0){
			if (b[j]<=a[i]){
				break;
			}else{
				j--;
			}
		}
		if (j!=(-1)){
			minD=min(minD,abs(a[i]-b[j]));
		}
	}
	cout << minD << "\n";
}
