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
	int minb = -2e9;
	int maxb = 2e9;
	for (int l=0;l<T;l++){
		string t; cin >> t;
		int num; cin >> num;
		char a; cin >> a;
		bool type = (a=='Y');
		if (t==">="){
			if (type){
				minb=max(num,minb);
			}else{
				maxb=min(maxb,num);
			}
		}else if (t==">"){
			if (type){
				minb=max(num+1,minb);
			}else{
				maxb=min(maxb,num);
			}
		}else if (t=="<="){
			if (type){
				maxb=min(maxb,num);
			}else{
				minb=max(num+1,minb);
			}
		}else{
			if (type){
				maxb=min(maxb,num-1);
			}else{
				minb=max(minb,num);
			}
		}
	}
	cout << ((minb>maxb)?"Impossible":to_string(minb)) << "\n";
}
