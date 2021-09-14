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
		int length = log10(N)+1;
		int even = 0;
		int odd = 0;
		int ce = 0;
		int co = 0;
		int count = 0;
		while (length>=0){
			if (count%2==0){
				even+=(N%10)*pow(10,ce);
				ce++;
			}else{
				odd+=(N%10)*pow(10,co);
				co++;
			}
			N/=10;
			count++;
			length--;
		}
		cout << (even+1)*(odd+1)-2 << "\n";
	}
}
