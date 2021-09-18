#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
#define pb push_back
#define eb emplace_back
#define countbits __builtin_popcount
#define beg0 __builtin_clz
#define terminal0 __builtin_ctz
#define mod 1e9+7
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
		int a[N],b[N];
		for (int i=0;i<N;i++){cin >> a[i];}
		for (int i=0;i<N;i++){cin >> b[i];}
		int pa[N];
		for (int i=0;i<N;i++){
			pa[(a[i]-1)/2]=i;
		}
		int posb[N];
		for (int i=0;i<N;i++){
			posb[(b[i])/2-1]=i;
		}
		int mind = 1e9; int minpa = 1e9;
		for (int i=0;i<N;i++){
			minpa=min(minpa,pa[i]);
			mind=min(mind,minpa+posb[i]);	
		}
		cout << mind << "\n";
	}
}
