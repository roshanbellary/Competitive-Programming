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
vector<int> ft(301,0);
void update(int i){
	while (i<=ft.size()){
		ft[i]++;
		i+=(i&(-i));
	}
}
int query(int i){
	if (i==0){return 0;}
	return ft[i]+query(i-(i&(-i)));
}
int main(){
	setIO();
	cin >> T;
	for (int l=0;l<T;l++){
		int N, M; cin >> N >> M;
		int a[M];
		int s[M];
		for (int i=0;i<M;i++){
			cin >> a[i];
			s[i]=a[i];
		}
		sort(s,s+M);
		int count = 1;
		map<int,int> m;
		for (int i=0;i<M;i++){
			int j=i+1;
			while (j<M){
				if (s[j]==s[i]){
					j++;continue;
				}else{
					break;
				}
			}
			i=j-1;
			m[s[i]]=count;
			count++;
		}
		int sum = 0;
		for (int i=0;i<M;i++){
			update(m[a[i]]);
			sum+=query(m[a[i]]-1);
		}
		fill(ft.begin(),ft.end(),0);
		cout << sum << "\n";
	}
}
