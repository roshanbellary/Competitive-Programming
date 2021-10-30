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
int mod=1e9+7;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int T, N, a[(int)2e5];
vector<int> div(int n){
	vector<int> vals;
	for (int i=1;i<=sqrt(n);i++){
		if (n%i==0){
			vals.pb(i);
			if (i!=(n/i))vals.pb(n/i);
		}
	}
	return vals;
}
int main(){
	setIO(); cin >> T;
	for (int l=0;l<T;l++){
		cin >> N; for (int i=0;i<N;i++) cin >> a[i];
		int mv = N+1;
		for (int p=0;p<=30;p++){
			int c = 0;
			for (int i=0;i<N;i++){
				if ((a[i]&(1<<p))!=0){
					c++;
				}
			}
			if (c==0) continue;
			if (mv==N+1) mv=c;
			else mv=gcd(mv,c);
		}
		if (mv!=N+1){
			vector<int> vals = div(mv);
			sort(vals.begin(),vals.end());
			for (int j:vals) cout << j << " ";
			cout << "\n";
		}else{
			for (int i=1;i<=N;i++){
				cout << i << " ";
			}
			cout << "\n";
		}
	}
}
