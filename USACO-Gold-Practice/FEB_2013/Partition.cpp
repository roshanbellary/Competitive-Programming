#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
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
int N, K;
ll g[15][15];
ll dp[15][15];
int main(){
	setIO("partition");
	cin >> N >> K;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			cin >> g[i][j];
		}
	}
	dp[0][0]=g[0][0];
	for (int i=1;i<N;i++){
		dp[i][0]=g[i][0]+dp[i-1][0];
		dp[0][i]=g[0][i]+dp[0][i-1];
	}
	for (int i=1;i<N;i++)
		for (int j=1;j<N;j++)
			dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+g[i][j];
	ll totval = 1e18;
	for (int a=0;a<(1<<(N-1));a++){
		int pos = 0;
		int count = 0;
		vector<int> p;
		while (pos<N){
			if (a&(1<<pos)){
				p.pb(pos);
				count++;
			}
			pos++;
		}
		if ((count<=K)&&(K-count<=N)){
			int rem = K-count;
			ll mdp[N][N];
			for (int i=0;i<N;i++){
				for (int j=0;j<N;j++){
					mdp[i][j]=1e18;
				}
			}
			if (p.size()>0){
				for (int i=0;i<N;i++){
					mdp[i][0]=dp[p[0]][i];
					for (int j=1;j<p.size();j++){
						mdp[i][0]=max(mdp[i][0],dp[p[j]][i]-dp[p[j-1]][i]);
					}
				}
			}else{
				p.pb(N-1);
				for (int i=0;i<N;i++){
					mdp[i][0]=dp[p[0]][i];
				}
			}
			for (int k=1;k<=rem;k++){
				for (int i=0;i<N;i++){
					for (int j=0;j<i;j++){
						ll res = max(mdp[j][k-1],dp[p[0]][i]-dp[p[0]][j]);
						for (int a=1;a<p.size();a++){
							res = max(res,dp[p[a]][i]-dp[p[a-1]][i]-(dp[p[a]][j]-dp[p[a-1]][j]));
						}
						mdp[i][k]=min(res,mdp[i][k]);
					}
				}
			}
			totval=min(totval,mdp[N-1][rem]);
		}
	}
	cout << totval << "\n";
}
