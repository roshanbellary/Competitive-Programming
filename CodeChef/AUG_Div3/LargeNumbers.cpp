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
int T;
ll dp[8][10];
int main(){
	setIO();
	cin >> T;
	memset(dp,0,sizeof(dp));
	queue<tuple<double,int>> q;
	q.push(tuple(1,1));
	while (!q.empty()){
		double res  = get<0>(q.front());
		int pos = get<1>(q.front());
		q.pop();
		if (pos==8) continue;
		for (int i=1;i<=9;i++){
			if (res*i/pos>=1){dp[pos][i-1]++;q.push(make_tuple((int)(res*i)/pos,pos+1));}
		}
	}
	ll sum = 0;
	for (int i=0;i<8;i++){
		for (int j=0;j<10;j++){
			sum+=dp[i][j];
			dp[i][j]=sum;
		}
	}
	for (int l=0;l<T;l++){
		int N; cin >> N;
		int len = log10(N)+1;
		int dig = (to_string(N)[0]-'0');
		if (dig!=1) cout << dp[len][dig-2] << "\n";
		else cout << dp[len-1][9] << "\n";
	}
}
