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
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
int mod=1000000007;
int HA=100000007;
int HB=101;
int hashing(int h, int ch) {
  return (1ll * h * HA + ch + HB) % mod;
}
int main() {
	setIO("censor");
	string S, T, R;cin >> S >> T;
	int thash = 0;
	for (int i=0;i<T.size();i++) thash = hashing(thash,T[i]-'a');
	vector<int> rhash(1, 0);
	vector<int> hashprev(1, 1);
	for (int i = 0; i < S.size(); i++) {
		R+=S[i];
		rhash.pb(hashing(rhash.back(), S[i] - 'a'));
		hashprev.pb((1ll * hashprev.back()*HA)%mod);
		if (R.size() >= T.size()) {
			int hsub = (1ll * rhash[R.size()-T.size()]*hashprev[T.size()]) % mod;
			int hsh = (mod + rhash.back() - hsub) % mod;
			if (hsh == thash && R.substr(R.size() - T.size()) == T) {
				R.resize(R.size() - T.size());
				rhash.resize(rhash.size() - T.size());
				hashprev.resize(hashprev.size() - T.size());
			}
		}
	}
	cout << R << endl;
	return 0;
}