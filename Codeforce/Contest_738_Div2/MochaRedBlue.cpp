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
int T;
int main(){
	setIO();
	cin >> T;
	for (int l=0;l<T;l++){
		int N; cin >> N;
		ll dp[N][2];
		string s; cin >> s;
		int t[N];
		for (int i=0;i<N;i++){
			if (s[i]=='?') t[i]=2;
			else if (s[i]=='R'){t[i]=0;}
			else{t[i]=1;}
		}
		for (int i=0;i<N;i++){
			for (int j=0;j<2;j++){
				dp[i][j]=1e15;
			}
		}
		for (int i=0;i<N;i++){
			if (t[i]==2){
				for (int j=0;j<2;j++){
					if (i!=0){
						dp[i][j]=min(dp[i-1][(j+1)%2],dp[i-1][j]+1);
					}else{
						dp[i][j]=0;
					}
				}
			}else{
				if (i!=0){
					dp[i][t[i]]=min(dp[i-1][t[i]]+1,dp[i-1][(t[i]+1)%2]);
				}else{
					dp[i][t[i]]=0;
				}
			}
		}
		int ptype = -1;
		string w = "";
		if (dp[N-1][0]<=dp[N-1][1]){
			w+="R"; ptype=0;
		}else{
			w+="B"; ptype=1;
		}
		char col[2] = {'R','B'};
		for (int i=N-2;i>=0;i--){
			if (t[i]==2){
				if (dp[i+1][ptype]==dp[i][ptype]+1){
					w+=col[ptype];
				}else{
					w+=col[(ptype+1)%2];
					ptype=(ptype+1)%2;
				}
			}else{
				w+=col[t[i]];
				ptype=t[i];
			}
		}
		reverse(w.begin(),w.end());
		cout << w << "\n";
	}
}
