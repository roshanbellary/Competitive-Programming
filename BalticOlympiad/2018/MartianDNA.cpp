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
int N,K,R;
int main(){
	setIO();
	cin >> N >> K >> R;
	int d[N]; int c[K];
	for (int i=0;i<N;i++) cin >> d[i];
	for (int i=0;i<N;i++){
		c[d[i]]++;
	}
	vector<int> r(K,0);
	for (int i=0;i<R;i++){
		int t, count; cin >> t >> count;
		if (c[t]<count){
			cout << "impossible\n";
			return 0;
		}
		r[t]=count;
	}
	vector<int> col(K,0);
	int nworks=R;
	int i=0,j=0;
	int mind = 1e9;
	while (true){
		if (nworks){
			if (j==N) break;
			if (col[d[j]]+1==r[d[j]]) nworks--;
			col[d[j]]++;
			j++;
		}else{
			mind=min(mind,j-i);
			if (col[d[i]]==r[d[i]]) nworks++;
			col[d[i]]--;
			i++;
		}
	}
	cout << ((mind==1e9)?"impossible":to_string(mind)) << "\n";
}
