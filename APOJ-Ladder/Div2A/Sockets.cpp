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
int N, M, K;int s[50];
int main(){
	setIO();cin >> N >> M >> K;
	for (int i=0;i<N;i++){cin >> s[i];s[i]--;}
	sort(s,s+N);
	int pos = N-1; int n = 0;
	while (K<M && pos>=0){
		K+=s[pos];n++;pos--;
	}
	cout << ((K<M)?"-1":to_string(n)) << "\n";
}
