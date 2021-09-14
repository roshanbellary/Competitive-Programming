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
char T;
char ranks[9]={'6','7','8','9','T','J','Q','K','A'};
int main(){
	setIO();
	cin >> T;
	string c1,c2;
	cin >> c1 >> c2;
	char s1=c1[1];char s2=c2[1];char r1=c1[0];char r2=c2[0];
	if ((s1==T)&&(s2!=T)) cout << "YES\n";
	else{
		if (s1!=s2) cout << "NO\n";
		else{
			int pos1,pos2;
			for (int i=0;i<9;i++){
				if (ranks[i]==r1) pos1=i;
				if (ranks[i]==r2) pos2=i;
			}
			if (pos1>pos2) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
