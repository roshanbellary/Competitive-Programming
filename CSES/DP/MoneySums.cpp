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
int N; int a[101];
bool s[(int)1e5+1];
int main(){
	setIO();
	cin >> N;for (int i=0;i<N;i++) cin >> a[i];
	sort(a,a+N);
	memset(s,false,sizeof(s));
	s[0]=true;
	for (int c=0;c<N;c++){
		for (int i=1e5;i>=0;i--){
			if (i-a[c]>=0){
				if (s[i-a[c]]) s[i]=true;
			}
		}
	}
	int count = 0;
	vector<int> sums;
	for (int i=1;i<=1e5;i++){if (s[i]){count++;sums.pb(i);}}
	cout << count << "\n";
	for (int j:sums) cout << j << " ";
	cout << "\n";
}
