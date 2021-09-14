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
int N, M;
bool g[201][201];
int dp[202][202];
int main(){
	setIO();
	cin >> N >> M;
	for (int i=0;i<N;i++){
		string s; cin >> s;
		for (int j=0;j<M;j++){
			if (s[j]=='X') g[i][j]=false;
			else g[i][j]=true;
		}
	}
	if (g[0][0]) dp[1][1]=0;
	else dp[1][1]=1;
	for (int i=0;i<=N+1;i++){
		dp[i][0]=0;
	}
	for (int i=0;i<=M+1;i++){
		dp[0][i]=0;
	}
	for (int i=2;i<=N+1;i++){
		if (!g[i-1][0]) dp[i][1]=dp[i-1][1]+1;
		else dp[i][1]=dp[i-1][1];
	}
	for (int i=2;i<=M+1;i++){
		if (!g[0][i-1]) dp[1][i]=dp[1][i-1]+1;
		else dp[1][i]=dp[1][i-1];
	}
	for (int i=2;i<=M+1;i++){
		for (int j=2;j<=N+1;j++){
			if (!g[i-1][j-1]) dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+1;
			else dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	ll area = 0;
	for (int i=1;i<=N+1;i++){
		for (int j=i;j<=N+1;j++){
			int valid = -1;
			for (int k=1;k<=M+1;k++){
				if ((!g[i-1][k-1])||(!g[j-1][k-1])){valid=-1;continue;}
				if (dp[j][k]-dp[i-1][k]-dp[j][k-1]+dp[i-1][k-1]==0){
					if (valid>0){
						area=max((ll)(j-i+1)*(k-valid+1),area);
					}else{
						area=max((ll)((j-i+1)),area);
						valid=k;
					}
				}
			}
		}
	}
	for (int i=0;i<=N;i++){
		for (int j=0;j<=M;j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			cout << g[i][j] << " ";
		}
		cout << "\n";
	}
	cout << area << "\n";
}
