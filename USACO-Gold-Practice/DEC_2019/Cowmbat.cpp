//Working sol created during contest
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
	string in = f+".in";
	string out = f+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	setIO();
}
int N, M, K;
int v[26][26];
int m[26][26];
int c[100001][26];
int dp[100001][26];
string S;
int main(){
	setIO("cowmbat");
	cin >> N >> M >> K;
	cin >> S;
	for (int i=0;i<M;i++){
		for (int j=0;j<M;j++){
			cin >> v[i][j];
		}
	}
	for (int i=0;i<M;i++){
		for (int j=0;j<M;j++){
			m[i][j]=1e9;
		}
	}
	for (int i=0;i<M;i++){
		m[i][i]=0;
		vector<bool> vi(M,false);
		while (true){
			int ind = -1;
			int mini = 1e9;
			for (int j=0;j<M;j++){
				if (!vi[j]&&(m[i][j]<mini)){ind=j;mini=m[i][j];}
			}
			if (ind<0) break;
			vi[ind]=true;
			for (int j=0;j<M;j++){
				m[i][j]=min(m[i][j],m[i][ind]+v[ind][j]);
			}
		}
	}
	for (int i=0;i<=N;i++){
		if (i==0){
			for (int j=0;j<M;j++){
				c[0][j]=0;
			}
		}else{
			for (int j=0;j<M;j++){
				c[i][j]=c[i-1][j]+m[S[i-1]-'a'][j];
			}
		}
	}
	vector<int> mins(N+1,0);
	for (int j=0;j<M;j++){
		dp[0][j]=0;
	}
	mins[0]=0;
	for (int i=1;i<=N;i++){
		int totmin = 1e9;
		for (int j=0;j<M;j++){
			if (i>=2*K){
				dp[i][j]=min(dp[i-1][j]+m[S[i-1]-'a'][j],mins[i-K]+c[i][j]-c[i-K][j]);
			}else{
				dp[i][j]=dp[i-1][j]+m[S[i-1]-'a'][j];
			}
			totmin=min(totmin,dp[i][j]);
		}
		mins[i]=totmin;
	}
	cout << mins[N] << "\n";
}
