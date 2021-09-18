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
int N;
int l[(int)5e5];
int v[(int)5e5];
vector<int> n;
int s = 0;
void dfs(int i, int t, int p){
	if (v[l[i]]==t){v[i]=t;return;}
	if (t==p) s++;
	v[i]=t;n.pb(i);
	if (t==1) t++;
	else t=1;
	if (v[l[i]]==0) dfs(l[i],t,p);
}
void reset(){
	for (int j:n) v[j]=0;
	n.clear();
}
int main(){
	setIO();cin >> N;
	for (int i=0;i<N;i++){ cin >> l[i];l[i]--;v[i]=0;}
	int sum = 0;
	for (int i=0;i<N;i++){
		if (v[i]==0){
			int maxi = -1;
			s=0;dfs(i,1,1);maxi=max(maxi,s);
			reset();
			s=0;dfs(i,2,2); 
			if (s>maxi){
				n.clear();
			}else{
				reset();
				s=0;
				dfs(i,1,1);
				n.clear();
			}
			maxi=max(maxi,s);
			sum+=maxi;
		}
	}
	cout << sum << "\n";
}