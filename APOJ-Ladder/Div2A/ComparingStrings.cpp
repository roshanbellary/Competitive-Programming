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
string a,b;
int main(){
	setIO();
	cin >> a >> b;
	if (a.length()==b.length()){
		int p[2]={-1,-1};
		int count = 0;
		for (int i=0;i<a.length();i++){
			if (a[i]!=b[i]){
				p[count]=i;
				count++;
				if (count==2) break;
			}
		}
		if (count==2) swap(a[p[0]],a[p[1]]);
		if ((a==b)) cout << "YES\n";
		else cout << "NO\n";
	}else cout << "NO\n";
}
