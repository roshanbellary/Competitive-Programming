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
#define f first
#define s second
int mod=1e9+7;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N, K,b[1000];
int setMax(int a){
	vector<int> hold; int buck = 0;
	for (int i=0;i<N;i++){
		buck+=b[i]/a;
		if ((b[i]%a)!=0)hold.pb(b[i]%a);
	}
	if (buck<K/2){
		return 0;
	}else{
		buck-=K/2;
		int col = buck*a; int r = K/2-buck;
		sort(hold.begin(),hold.end(),greater<int>());
		if (hold.size()<r) return 0;
		for (int i=0;i<r;i++){
			col+=hold[i];
		}
		return col;
	}
}
int main(){
	setIO("berries");cin >> N >> K; int mv = 0;
	for (int i=0;i<N;i++){cin >> b[i];mv=max(mv,b[i]);}
	int maxV = 0;
	for (int i=1;i<=mv;i++){
		maxV=max(maxV,setMax(i));
	}
	cout << maxV << "\n";
}
