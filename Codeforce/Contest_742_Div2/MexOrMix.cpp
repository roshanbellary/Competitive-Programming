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
		int a,b; cin >> a >> b;
		int len = a;
		int mods = (a-1)%4;
		if (mods==0){
			if (b!=(a-1)){
				if ((a^(a-1))!=b) len++;
				else len+=2;
			}
		}else if (mods==1){
			if (b!=1){
				if ((a^1)!=b) len++;
				else len+=2;
			}
		}else if (mods==2){
			if (b!=a){
				if (b!=0) len++;
				else len+=2;
			}
		}else{
			if (b!=0){
				if (b!=a) len++;
				else{len+=2;}
			}
		}
		cout << len << "\n";
	}
}
