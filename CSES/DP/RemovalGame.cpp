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
ll m[(int)5e3][(int)5e3];
ll x[(int)5e3];
ll p[(int)5e3];
void checkPos(int l, int r){
	if (l==r){
		if (N%2==1) m[l][r]=x[l];
		else m[l][r]=0;
	}else{
		if (m[l+1][r]==-1e18) checkPos(l+1,r);
		if (m[l][r-1]==-1e18) checkPos(l,r-1);
		if ((N-(r-l+1))%2==0){
			m[l][r]=max(m[l+1][r]+x[l],m[l][r-1]+x[r]);
		}else{
			if (p[r]-p[l]-m[l+1][r]+x[l]>p[r]-p[l]+x[l]-m[l][r-1]){
				m[l][r]=m[l+1][r];
			}else{
				m[l][r]=m[l][r-1];
			}
		}
	}
}
int main(){
	setIO();
	cin >> N; for (int i=0;i<N;i++) cin >> x[i];
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			m[i][j]=-1e18;
		}
	}
	for (int i=0;i<N;i++){
		if (i) p[i]=p[i-1]+x[i];
		else p[i]=x[i];
	}
	checkPos(0,N-1);
	cout << m[0][N-1] << "\n";
}
