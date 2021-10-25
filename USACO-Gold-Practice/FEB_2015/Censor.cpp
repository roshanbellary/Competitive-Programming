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
ll mod=1e9+7,p=31;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
ll pows[(int)1e5+1];
int N;
string S;
vector<string> w;
map<int,set<ll>> m;
set<int> lengths;
void setPowers(){
	pows[0]=1;
	for (int i=1;i<=1e5;i++){
		pows[i]=(pows[i-1]*p)%mod;
	}
}
ll calcHash(string &s){
	ll hash = 0;
	for (int i=0;i<s.length();i++){
		hash+=((s[i]-'a'+1)*(pows[s.length()-1-i]))%mod;
		hash%=mod;
	}
	return hash;
}
int main(){
	setIO("censor");setPowers(); 
	cin >> S >> N;
	for (int i=0;i<N;i++){
		string s; cin >> s;
		lengths.insert(s.size());m[s.length()].insert(calcHash(s));
	}
	vector<ll> currHash;
	currHash.pb(0);
	string res = "";
	for (int i=0;i<S.size();i++){
		if (currHash.size()==0) currHash.pb(0);
		res+=S[i];
		currHash.pb((currHash.back()*p+(S[i]-'a'+1))%mod);
		auto itr = lengths.upper_bound(res.size());
		if (itr==lengths.begin()) continue;
		itr--;
		while (true){
			int diffs = ((currHash[currHash.size()-1]-(currHash[currHash.size()-*itr-1]*pows[*itr])%mod)%mod+mod)%mod;
			auto finder = m[*itr].find(diffs);
			if (finder!=m[*itr].end()){
				currHash.resize(currHash.size()-*itr);
				res.resize(res.size()-*itr);break;
			}
			if (itr==lengths.begin()) break;
			itr--;
		}
	}
	cout << res << "\n";
}
