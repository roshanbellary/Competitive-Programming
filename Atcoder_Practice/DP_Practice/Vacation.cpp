#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
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
int main(){
	setIO();
	cin >> N;
	int v[N][3];
	int dp[N][3];
	for (int i=0;i<N;i++){
		int a,b,c; cin >> a >> b >> c;
		v[i][0]=a;v[i][1]=b;v[i][2]=c;
	}
	for (int i=0;i<3;i++) dp[0][i]=v[0][i];
	for (int i=1;i<N;i++){
		for (int j=0;j<3;j++){
			dp[i][j]=max(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3])+v[i][j];
		}
	}
	cout << max(max(dp[N-1][0],dp[N-1][1]),dp[N-1][2]) << "\n";

}
