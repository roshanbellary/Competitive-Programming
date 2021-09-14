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
int main(){
	setIO();
	int N; cin >> N;
	string w; cin >> w;
	char c[4] = {'A','T','C','G'};
	int dp[N][4];
	memset(dp,0,sizeof(dp));
	for (int i=0;i<N;i++){
		for (int j=0;j<4;j++){
			if (w[i]==c[j]){
				if (i!=0){
					dp[i][j]=dp[i-1][j]+1;
					dp[i][(j+1)%4]=dp[i-1][(j+1)%4];
					dp[i][(j+2)%4]=dp[i-1][(j+2)%4];
					dp[i][(j+3)%4]=dp[i-1][(j+3)%4];
				}else{
					dp[i][j]=1;
					dp[i][(j+1)%4]=0;
					dp[i][(j+2)%4]=0;
					dp[i][(j+3)%4]=0;
				}
				break;
			}
		}
	}
	int counts = 0;
	for (int i=0;i<N;i++){
		for (int j=i+1;j<N;j++){
			if (i>0){
				if ((dp[j][1]-dp[i-1][1]==dp[j][0]-dp[i-1][0])&&(dp[j][3]-dp[i-1][3]==dp[j][2]-dp[i-1][2])) counts++;
			}else{
				if ((dp[j][1]==dp[j][0])&&(dp[j][3]==dp[j][2])) counts++;
			}

		}
	}
	cout << counts << "\n";
}
