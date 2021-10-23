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
int mod=998244353;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
string S;
ll p[(int)2e5];
int main(){
	setIO(); cin >> S;
	p[0]=1;
	for (int i=1;i<2e5;i++){
		p[i]=(2*p[i-1])%mod;
	}
	ll sum = 0;
	ll col = 0;
	for (int i=0;i<S.size();i++){
		col=(10*col)%mod+(S[i]-'0')*i;
		if (i!=S.size()-1){sum+=((col+(S[i]-'0')*p[i])*(p[S.size()-2-i]))%mod;sum%=mod;}
		else{sum+=((col+(S[i]-'0')*p[i]))%mod;sum%=mod;}
		col+=(S[i]-'0');
		cout << sum << " " << col << "\n";
	}
	cout << sum << "\n";
}
